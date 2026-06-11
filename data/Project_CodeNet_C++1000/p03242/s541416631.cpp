#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  string s;
  cin >> s;

  string o;

  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      o += "9";
    }
    if (s[i] == '9') {
      o += "1";
    }
  }

  cout << o << endl;
}
