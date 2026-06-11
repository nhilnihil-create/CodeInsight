#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  string S; cin >> S;
  int l = S.length();
  int result = l;
  for (int i=1; i<l; i++) { 
    if (S[i-1]!=S[i]) result = min(result, max(i, l-i));
  }
  cout << result << endl;
  return 0;
}