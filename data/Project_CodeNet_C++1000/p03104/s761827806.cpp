#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  //cout << a % b <<endl;
  ans += abs((b+1) / 2 - a/2) % 2;
  for(int i = 1;i < 41; i++){
    ll m = pow(2, i);
    ll k = 2*m;
    ll p = (a-1) % k, q = b % k;
    if(p >= m) p = (p-m+1) % 2;
    else p = 0;
    if(q >= m) q = (q-m+1) % 2;
    else q = 0;
    if(abs(p-q) % 2) ans += m;
  }
  cout << ans <<endl;
}