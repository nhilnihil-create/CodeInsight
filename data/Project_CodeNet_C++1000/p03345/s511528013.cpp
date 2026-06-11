#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  if (K%2==0) cout << A-B << endl;
  else cout << B-A << endl;
}