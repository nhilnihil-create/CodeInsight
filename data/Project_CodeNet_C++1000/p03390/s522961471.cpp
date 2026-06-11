#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    if(a > b)swap(a, b);
    ll rnk = 1LL * a * b;
    ll lo = 0, hi = rnk - 1;
    while(lo < hi){
      ll mid = (lo + hi + 1) / 2;
      ll m = mid / 2;
      ll F = mid + (mid >= a ? 1 : 0);
      ll S = mid + (mid >= b ? 1 : 0);
      bool g = 1;
      for(ll x = max(1LL, m - 50);x <= min(m + 50, mid);x++){
        ll L = x;
        ll R = mid - x + 1;
        if(L >= a)
          L++;
        if(R >= b)
          R++;
        if((rnk + R - 1) / R <= L || rnk <= L * R){
          g = 0;
          break;
        }

      }
      if(g)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << endl;
  }
  return 0;
}
