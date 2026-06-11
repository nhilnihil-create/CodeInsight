#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
vector< vector<ll> > ans;
vector<vector<ll>> vac;
ll vacation(int N,int i){
  if(N<0){
      return 0;
  }
  if(ans[N][i]!=-1)
  	return ans[N][i];
  for(int j=0;j<3;j++){
    if(i!=j){
      ans[N][i] = max(vac[N][j]+vacation(N-1,j),ans[N][i]);
    }
  }
  return ans[N][i];
}
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #ifdef SANS
        freopen("ongoingin.txt","r",stdin);
        freopen("ongoingout.txt","w",stdout);
    #endif
  ll N;
  cin>>N;
  vac.resize(N,vector<ll>(3));
  ans.resize(N);
  for(int i=0;i<N;i++){
    ans[i].resize(3);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      ans[i][j] = -1;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      cin>>vac[i][j];
      //cout<<vacation[i][j]<<" ";
    }
  }
  int final_ans = max(vacation(N-1,0),max(vacation(N-1,1),vacation(N-1,2)));
  cout<<final_ans<<endl;
  return 0;
  /*
  for(int i=0;i<1e5;i++){
    cout<<i+1<<endl;
  }*/
}
