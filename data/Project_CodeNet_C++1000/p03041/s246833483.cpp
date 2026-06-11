#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
int main() {
  int N,K;
  cin >> N >> K;
  K--;
  string S;
  cin >> S;
  S[K] = tolower(S[K]);
  cout << S << endl;

  return 0;
}