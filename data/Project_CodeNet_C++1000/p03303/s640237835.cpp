#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int w;cin>>w;
  string res;
  rep(i,(int)s.length()){
    if(i%w==0)res+=s[i];
  }
  cout<<res<<endl;
  return 0;
}
