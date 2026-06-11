#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  string str;
  cin >> str;

  ll K;
  scanf("%lld", &K);

  ll firstIndex = -1;
  for (ll i = 0; i < str.size(); i++) {
    if (str[i] != '1') {
      firstIndex = i;
      break;
    }
  }

  if (firstIndex == -1) {
    cout << (str[0]) << endl;
    return 0;
  }

  if (K >= firstIndex + 1) {
    cout << (str[firstIndex]) << endl;
    return 0;
  }

  cout << (1) << endl;
}
