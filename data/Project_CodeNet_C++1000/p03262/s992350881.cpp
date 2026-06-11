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
lint gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
signed main(){  
  int n,x;cin>>n>>x;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  lint res=0;
  rep(i,n){
      res=gcd(res,abs(x-a[i]));
      //cout<<res<<"\n";
  }
  cout<<res<<"\n";
  return 0;
}