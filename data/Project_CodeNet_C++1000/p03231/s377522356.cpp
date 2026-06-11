#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

ll GCD(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return GCD(b, a % b);
}

ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  const ll lcm = LCM(n, m);
  const ll gcd = GCD(n, m);

  // string a, b;
  // a.resize(lcm, '_');
  // b.resize(lcm, '_');

  // const ll n_cd = lcm / n;
  // for (size_t i = 0; i < s.size(); i++) {
  //   a[i * n_cd] = s[i];
  // }

  // const ll m_cd = lcm / m;
  // for (size_t i = 0; i < t.size(); i++) {
  //   b[i * m_cd] = t[i];
  // }
  // for (size_t i = 0; i < lcm; i++) {
  //   if (a[i] != '_' && b[i] != '_') {
  //     if (a[i] != b[i]) {
  //       ok = false;
  //     }
  //   }
  // }

  const ll n_cd = lcm / m;
  const ll m_cd = lcm / n;

  string a;
  string b;

  for (size_t i = 0; i < s.size(); i += n_cd) {
    a.push_back(s[i]);
  }
  for (size_t i = 0; i < t.size(); i += m_cd) {
    b.push_back(t[i]);
  }
  
  if (a == b) {
    cout << lcm << endl;
  } else {
    cout << (-1) << endl;
  }
}