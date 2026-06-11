#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  string s;cin>>s;
  int q;cin>>q;
  vector<int> k(q);
  rep(i,q)cin>>k[i];
  rep(x,q){
      lint res=0;
      lint d=0;
      lint m=0;
      lint dm=0;
      rep(i,k[x]){
          if(s[i]=='D')++d;
          else if(s[i]=='M'){
              ++m;dm+=d;
          }
          else if(s[i]=='C')res+=dm;
      }
      for(int i=k[x];i<n;++i){
          if(s[i-k[x]]=='D'){
              --d;dm-=m;
          }
          else if(s[i-k[x]]=='M'){
              --m;
          }
          if(s[i]=='D')++d;
          else if(s[i]=='M'){
              ++m;dm+=d;
          }
          else if(s[i]=='C')res+=dm;
      }
      cout<<res<<"\n";
  }
  return 0;
}