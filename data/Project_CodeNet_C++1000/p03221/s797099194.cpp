#include <bits/stdc++.h>
#include <ios>
#include <iomanip>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

// x^y%p
long long modpow(long long x, long long y, long long p=1) {
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = res * x % p;
        y = y>>1;
        x = x * x % p;
    }
    return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long N, M;
  cin >> N >> M;
  vector<long long> P(M), Y(M);
  vector<vector<long long>> prefecture(N+1);
  for(long long i = 0; i < M; i++) {
    cin >> P[i] >> Y[i];
    prefecture[P[i]].push_back(Y[i]);
  }

  for(long long i = 0; i < N; i++) {
    sort(prefecture[i+1].begin(), prefecture[i+1].end());
  }

  for(long long i = 0; i < M; i++) {
    cout << setfill('0') << setw(12) << P[i]*1000000+int(lower_bound(prefecture[P[i]].begin(), prefecture[P[i]].end(), Y[i])-prefecture[P[i]].begin())+1 << endl;
  }

  return 0;
}
