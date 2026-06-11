#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  if ((B-A)%2==0) cout << "Alice" << endl;
  else cout << "Borys" << endl;
}