#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
vector<int> ans;
vector<int> h;
int cnt=0;
int frog1(int N)
{
    cout<<cnt<<" "<<ans[N]<<endl;

  if(N<=0)return 0;
  if(N==1)return abs(h[1]-h[0]);
  if(ans[N]==-1)
  {
    ans[N] = min(abs(h[N]-h[N-1])+frog1(N-1),abs(h[N]-h[N-2])+frog1(N-2));
  }
  return ans[N];
}
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  ll N,K;
  cin>>N>>K;
  h.resize(N);
  for(int i=0;i<N;i++){
    cin>>h[i];
  }
  ans.resize(N);
  for(int i=0;i<N;i++){
    ans[i] = -1;
  }
  ans[0] = 0;
  ans[1] = abs(h[1]-h[0]);
  for(int i=2;i<N;i++){
    for(int j=1;j<=K;j++){
      if(i-j<0){
        break;
      }
      if(j==1){
        ans[i] = abs(h[i]-h[i-j])+ans[i-j];
      }
      else{
        ans[i] = min(abs(h[i]-h[i-j])+ans[i-j],ans[i]);  
      }
    }
    
  }
  cout<<ans[N-1]<<endl;
  return 0;
  /*
  for(int i=0;i<1e5;i++){
    cout<<i+1<<endl;
  }*/
}
