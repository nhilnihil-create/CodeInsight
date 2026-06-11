#include "bits/stdc++.h"
using namespace std;
#define debug(var) cout << #var << ": " << var << endl;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
using ll = long long;
using ull = unsigned long long;
using vvint = vector<vector<int>>;
constexpr ll mod = 1e9 + 7;

int main() {

  int A, B, C; cin >> A >> B >> C;
  if ((A <= C && C <= B) || (B <= C && C <= A))cout << "Yes";
  else cout << "No";

  return 0;
}