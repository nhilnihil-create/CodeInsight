#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  string s;
  cin >> s;

  string y = s.substr(0, 4);
  string m = s.substr(5, 2);
  string d = s.substr(8, 2);

  ll v = stoi(y) * 10000 + stoi(m) * 100 + stoi(d);

  if (v <= 20190430) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
}
