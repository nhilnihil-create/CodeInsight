#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 3e5 + 5;

Modint fact [MAX_N];
Modint invfact [MAX_N];

Modint choose (int n, int k) {
  if (k < 0 || n < k) return Modint(0);
  return fact[n] * invfact[k] * invfact[n - k];
}

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = Modint(i) * fact[i - 1];
  }

  invfact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    invfact[i] = inv(Modint(i)) * invfact[i - 1];
  }

  ll n, a, b, k;
  cin >> n >> a >> b >> k;

  Modint ans (0);
  for (ll u = 0; u <= n && u * a <= k; u++) {
    if ((k - u * a) % b == 0) {
      ll v = (k - u * a) / b;
      ans += choose(n, u) * choose(n, v);
    }
  }

  cout << ans << endl;
}
