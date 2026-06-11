#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <bits/stdc++.h> 
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

char c[500][500];

bool check(int x,int m){
  rep(i,m){
    rep(j,m){
      if(c[(i+x)%m][j]!=c[(j+x)%m][i]){
        return false;
      }
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  rep(i,n)rep(j,n)cin >> c[i][j];
  ll ans=0;
  rep(i,n){
    if(check(i,n))ans+=n;
  }
  cout << ans << endl;
return 0;}