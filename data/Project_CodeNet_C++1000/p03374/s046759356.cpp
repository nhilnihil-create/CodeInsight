#include <iostream>
using namespace std;

typedef long long ll;

#define MAX 100002

int main()
{
  ll n, c;
  ll x[MAX], v[MAX];

  cin >> n >> c;
  for(int i = 1; i <= n; i++){
    cin >> x[i] >> v[i];
  }

  ll l[MAX], r[MAX];
  ll lmax[MAX], rmax[MAX];
  for(int i = 1; i <= n; i++){
    r[i] = r[i-1] + v[i];
    rmax[i] = max(rmax[i-1], r[i] - x[i]);
  }

  for(int i = n; i > 0; i--){
    l[i] = l[i+1] + v[i];
    lmax[i] = max(lmax[i+1], l[i] - (c - x[i]));
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++){
    if(i != n) ans = max(ans, r[i] - 2*x[i] + lmax[i+1]);
    if(i != 1) ans = max(ans, l[i] - 2*(c - x[i]) + rmax[i-1]);
    ans = max(ans, max(rmax[i], lmax[i]));
  }

  cout << ans << endl;

  return 0;
}
