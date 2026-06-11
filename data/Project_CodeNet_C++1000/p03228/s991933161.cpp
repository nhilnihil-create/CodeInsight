#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll a,b,k; cin >> a >> b >> k;
  REP(i,k){
    ll t;
    if(i%2==0){
      t = a/2;
      a -= t + a%2;
      b += t;
    }else{
      t = b/2;
      a += t;
      b -= t + b%2;
    }
  }
  cout << a << " " << b << endl;
}