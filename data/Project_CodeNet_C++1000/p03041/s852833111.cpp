#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  string T = "";
  rep(i,K-1) T += S[i];
  int n = S[K-1] - 'A';
  char c = 'a' + n;
  T += c;
  if (N > K) {
    for (int i = K; i < N; i++) T += S[i];
  }
  
  cout << T << endl;
}
