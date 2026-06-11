#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int N;
  cin >> N;
  vector<int> b(N);
  for (int i=0; i<N; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> res;
  for (int i=0; i<N; i++) {
    int pivot = -1;
    for (int j=b.size()-1; j>=0; j--) {
      if (b[j]==j) {
        pivot = j;
        break;
      }
    }
    if (pivot==-1) {
      cout << -1 << endl;
      return 0;
    }
    res.push_back(pivot+1);
    b.erase(b.begin()+pivot);
  }
  reverse(res.begin(), res.end());
  for (auto v: res) cout << v << endl;
  return 0;
}