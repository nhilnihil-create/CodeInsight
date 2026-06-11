#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

const int max_fac = 5 * 1e5;
long long fac[max_fac], finv[max_fac], inv[max_fac];
void ComInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max_fac; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long Comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int n;
  const int max_n = 1e5;
  vector<pair<int, int>> a;

  ComInit();

  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    a.push_back(make_pair(x, i));
  }

  sort(a.begin(), a.end());

  int ans = 0;

  int i = n-1;
  int l = 0;
  int r = i - 1;
  int mid = 0;
  int trgt = a[i].first / 2;
  while(r - l > 1){
    int mid = (l + r) / 2;
    if(a[mid].first <= trgt) l = mid;
    else r = mid;
  }
  ans = a[l].first;
  if(a[n-1].first - a[l].first * 2 > a[l+1].first * 2 - a[n-1].first) ans = a[l+1].first;

  cout << a[n-1].first << " " << ans << endl;
  return 0;
}