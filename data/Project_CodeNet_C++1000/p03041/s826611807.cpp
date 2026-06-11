#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;
  S[K-1] += 32;
  cout << S << endl;
  return 0;
}