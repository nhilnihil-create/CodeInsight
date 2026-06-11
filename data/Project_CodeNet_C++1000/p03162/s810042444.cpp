#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
int cnt = 0;
//vector< vector<ll> > ans;
//vector< vector<bool>> v;
vector<vector<ll>> vac;
/*ll vacation(int N,int i){
  if(N==0){
      return vac[N][i];
  }
  for(int j=0;j<3;j++){
    if(ans[N-1][j]==-1){
      cnt++;
      ans[N-1][j] = vacation(N-1,j);
    }
  }
  for(int j=0;j<3;j++){
    if(i!=j){
      ans[N][i] = max(vac[N][i]+ans[N-1][j],ans[N][i]);
    }
  }
  return ans[N][i];
}*/
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  ll N;
  cin>>N;
  //ans.resize(N);
  vac.resize(N);

  for(int i=0;i<N;i++){
    //ans[i].resize(3);
    vac[i].resize(3);
  }/*
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      ans[i][j] = -1;
    }
  }*/
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      cin>>vac[i][j];
      //cout<<vacation[i][j]<<" ";
    }
  }
  for(int i=1;i<N;i++){
    vac[i][0] = max(vac[i][0]+vac[i-1][1],vac[i][0]+vac[i-1][2]);
    vac[i][1] = max(vac[i][1]+vac[i-1][0],vac[i][1]+vac[i-1][2]);
    vac[i][2] = max(vac[i][2]+vac[i-1][0],vac[i][2]+vac[i-1][1]);     
  }
  /*ll final_ans = vacation(N-1,0);

  final_ans = max(final_ans,vacation(N-1,1));
  final_ans = max(final_ans,vacation(N-1,2));

  cout<<final_ans<<endl;
  cout<<cnt<<endl;
  */
  ll final_ans = max(vac[N-1][0],max(vac[N-1][1],vac[N-1][2]));
  cout<<final_ans<<endl;
  //cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
  
  return 0;
  /*
  for(int i=0;i<1e5;i++){
    cout<<i+1<<endl;
  }*/

}
