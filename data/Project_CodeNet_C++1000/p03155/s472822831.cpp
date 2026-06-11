#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  cout << (N-H+1)*(N-W+1) << endl;
}