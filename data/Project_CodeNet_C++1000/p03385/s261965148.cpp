#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s == "abc") {
    cout << "Yes" << "\n";
  }
  else {
    cout << "No" << "\n";
  }
}
