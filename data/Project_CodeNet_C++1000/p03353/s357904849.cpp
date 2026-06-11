#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();

  priority_queue<string, vector<string>, greater<string>> pq;
  for (ll i = 0; i < n; i++) {
    for (ll j = i; j < min(n, i + k); j++) {
      string t;
      for (ll l = i; l <= j; l++) {
        t.push_back(s[l]);
      }
      pq.push(t);
    }
  }
  for (ll i = 0; i < k - 1; i++) {
    string t = pq.top();
    while (t == pq.top()) pq.pop();
  }
  cout << pq.top() << endl;
}