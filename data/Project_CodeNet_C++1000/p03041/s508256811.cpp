#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  S[K - 1] -= 'A' - 'a';
  cout << S << endl;
}