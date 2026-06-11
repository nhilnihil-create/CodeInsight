#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int s(int n){
  int res=0;
  while(n){
    res+=n%10;
    n/=10;
  }
  return res;
}
long double f(int n){
  return (long double)n/s(n);
}
//main
signed main(){
  int K;cin>>K;
  int now=0;int t=1;
  std::vector<int> ans;
  while(ans.size()<K){
    for(int i=1;i<=200;i++){
      if(f(now+i*t)>f(now+(i+1)*t))break;
      //cout<<now<<" "<<i<<" "<<t<<endl;
      if(ans.size()==0){ans.push_back(1);continue;}
      if(now+i*t>ans[ans.size()-1])ans.push_back(now+i*t);
    }
    //cout<<now<<endl;
    now*=10;now+=9;t*=10;
    //cout<<now<<endl;
  }
  for(int i=0;i<K;i++)cout<<ans[i]<<endl;
}
