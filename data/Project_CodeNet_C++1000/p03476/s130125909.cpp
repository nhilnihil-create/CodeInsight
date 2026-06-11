#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
vector<bool> isPrime;
void sieve(int max) {
  if (max+1 > isPrime.size()) isPrime.resize(max+2,true);

  isPrime[0] = false;
  isPrime[1] = false;
  
  for (int i = 2; i*i <= max; i++)
  {
    if (!isPrime[i]) continue;
    for (int j = 2; j*i <= max; j++) isPrime[i*j] = false;
  }
}
const int MAX_N = 100010;
int main() {
  int q;
  cin >> q;
  sieve(MAX_N);
  vector<int> sum(MAX_N+1,0);
  for (int i = 3; i <= MAX_N; i += 2)
  {
    if (isPrime[i] && isPrime[(i+1)/2]) sum[i] = sum[i-2] + 1;
    else sum[i] = sum[i-2];
  }
  //rep(i,10) cout << sum[i] << endl;
  int l,r;
  rep(i,q)  {
    cin >> l >> r;
    cout << sum[r] - sum[max(l-2,0)] << endl;
  }
  return 0;
}