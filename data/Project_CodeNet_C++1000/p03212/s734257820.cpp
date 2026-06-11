#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> sft;
  
  //sft.emplace_back(0);
  ll tens = 1;
  int i;
  while(tens < n) {
    i = 0;
    while (1) {
      ll t;
      if (sft.size() == 0) t = 0;
      else t = sft[i];
      if (t >= tens) break;
      i++;
      sft.emplace_back(3*tens + t);
      sft.emplace_back(5*tens + t);
      sft.emplace_back(7*tens + t);
    }
    tens *= 10;
  }

  int cnt = 0;
  for (ll as: sft) {
    ll a = as;
    //if (dbgflag) cout << a << endl;
    if (a > n) continue;
    bool thr = false, fiv = false, sev = false;
    while (a > 0) {
      int md = a % 10;
      if (md == 3) thr = true;
      else if (md == 5) fiv = true;
      else if (md == 7) sev = true;
      else {
        thr = false;
        break;
      }
      a /= 10;
    }
    if (thr && fiv && sev) {
      if (dbgflag) cout << as << endl;
      cnt++;
    }
  }

  cout << cnt << endl;
  
}
