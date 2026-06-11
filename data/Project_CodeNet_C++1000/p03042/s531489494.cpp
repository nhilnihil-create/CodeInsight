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
  string s;
  cin >> s;

  ll n1 = stoi(s.substr(0, 2));
  ll n2 = stoi(s.substr(2, 4));

  bool isYYMM = false;
  bool isMMYY = false;

  if (n1 >= 1 && n1 <= 12) {
    isMMYY = true;
  }
  if (n2 >= 1 && n2 <= 12) {
    isYYMM = true;
  }

  if (isYYMM && isMMYY) {
    cout << ("AMBIGUOUS ") << endl;
  } else if (isYYMM) {
    cout << ("YYMM") << endl;
  } else if (isMMYY) {
    cout << ("MMYY") << endl;
  } else {
    cout << ("NA") << endl;
  }
}
