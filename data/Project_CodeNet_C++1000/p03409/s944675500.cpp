#include <iostream>
#include<string>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include <limits>
#include <numeric>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define fi first
#define se second
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL

int main(){
  int n;cin>>n;
  vector<P>r(n),b(n);
  rep(i,n)cin>>r[i].fi>>r[i].se;
  rep(i,n)cin>>b[i].fi>>b[i].se;
  sort(ALL(b));

  int ans=0;
  bool r_used[n];
  rep(i,n)r_used[i]=0;
  rep(i,n){
    P best=make_pair(0,-MAX);
    rep(j,n){
      if(r[j].fi<b[i].fi && r[j].se<b[i].se && r_used[j]==0){
        if(best.se<r[j].se){
          best.fi=j;best.se=C_MAX(best.se,r[j].se);
        }
      }
    }
    if(best.se!=-MAX){
      r_used[best.fi]=1;
      ans++;
    }

  }
  cout<<ans<<endl;
}