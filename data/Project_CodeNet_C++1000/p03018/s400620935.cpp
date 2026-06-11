#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  string s;
  cin >> s;
  ll n = s.size();

  ll ans = 0, a = 0, bc = 0;
  string task, reset;
  for (ll i = 0; i < n; i++) {
    if (s[i] == 'A') {
      if (task.size() == 0 || task.back() == 'A') {
        task.push_back(s[i]);
        a++;
      }
      else {
        ans += a * bc;
        if (task.back() == 'C') {
          task = task.substr(0, a);
          task.push_back(s[i]);
          a++;
          bc = 0;
        }
        else {
          task = reset;
          task.push_back(s[i]);
          a = 1;
          bc = 0;
        }
      }
    }
    else if (s[i] == 'B') {
      if (i == n - 1) ans += a * bc;
      else if (s[i + 1] == 'C') {
        bc++;
        task += "BC";
        i++;
      }
      else {
        ans += a * bc;
        task = reset;
        a = 0;
        bc = 0;
      }
    }
    else {
      ans += a * bc;
      task = reset;
      a = 0;
      bc = 0;
    }
  }
  if (s.size() >= 2 && s[n - 2] == 'B' && s[n - 1] == 'C') ans += a * bc;

  cout << ans << endl;
}