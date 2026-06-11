#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a < b || d < b){
    cout << "No\n";
    return;
  }
  ll L = c + 1;
  ll R = b - 1;
  if(L > R){
    cout << "Yes\n";
    return ;
  }
  ll t = __gcd(b,d);
  a -= L;
  a = max(a, -a);
  ll sz = R - L;
  ll pv = a - a % t;
  if(a >= pv && a <= pv + sz)
    cout << "No\n";
  else
    cout << "Yes\n";
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int i = 0 ; i < testc; i ++ ){
    solve();
  }
  return 0;
}