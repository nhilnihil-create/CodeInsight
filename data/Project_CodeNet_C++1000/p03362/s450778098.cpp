#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[100000];
vector<ll> prime1;
bool is_prime[100000];

ll sieve(ll n) {
  ll p = 0;
  for (ll i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n; i++) {
    if (is_prime[i]) {
      if (i%10==1) {prime1.push_back(i);}
      prime[p++] = i;
      for (ll j = 2*i; j <= n; j+=i) is_prime[j] = false;
    }
  }
  return p;
}

int main() {
  ll N; cin >> N;
  sieve(55555);
  for (ll i = 0; i < N; i++) {
    cout << prime1[i] << " ";
  }
  cout << endl;
}