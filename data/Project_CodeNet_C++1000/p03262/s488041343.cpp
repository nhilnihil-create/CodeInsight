#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() { 
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N+1);
    for (int i = 0; i<N; ++i)cin >> x[i];
    x[N] = X;
    sort(x.begin(), x.end());
    vector<ll> dif(N);
    for (int i = 0; i < N; i++) dif[i] = x[i + 1] - x[i];
    ll g = *min_element(dif.begin(), dif.end());
    for (int i = 0; i < N; i++){
      g = gcd(g, dif[i]);
    }
      cout << g << endl;
    return 0;
}