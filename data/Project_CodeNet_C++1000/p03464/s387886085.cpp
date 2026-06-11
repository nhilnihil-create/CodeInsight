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

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n)cin >> a[n-1-i];
  ll m=2,M=2;
  if(a[0]!=2){
    cout << -1 << endl;
    return 0;
  }
  REP(i,1,n){
    M+=a[i-1]-1;
    if(M%a[i]!=0){
      M-=M%a[i];
    }
    if(m%a[i]!=0){
      m+=a[i]-m%a[i];
    }
    if(m>M || M<a[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  M+=a[n-1]-1;
  
  cout << m << ' ' << M << endl;
return 0;}