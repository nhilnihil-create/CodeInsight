#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()


int main() {
  int R;
  cin >> R;

  string s;
  if(R < 1200) s = "ABC";
  else if(R < 2800) s = "ARC";
  else s = "AGC";

  cout << s << ln;
 }
