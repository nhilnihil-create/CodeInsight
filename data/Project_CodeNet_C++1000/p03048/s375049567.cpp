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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int r,g,b,n;cin>>r>>g>>b>>n;
  int res=0;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=n;++j){
      int buf=n-i*r-j*g;
      if(buf>=0&&buf%b==0)++res;
    }
  }
  cout<<res<<"\n";
  return 0;
}
