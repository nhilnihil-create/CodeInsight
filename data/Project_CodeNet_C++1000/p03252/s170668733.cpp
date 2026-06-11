#include<bits/stdc++.h>
using namespace std;
int main () {
  string S[2];
  cin >> S[0] >> S[1];
  int S_[2][200001];
  int N = (int)S[1].size();
  for (int i = 0; i < 2; i ++) {
    string a = "";
    for (int j = 0; j < N; j ++) {
      int n = a.size();
      int p = 0;
      while (p < n && a[p] != S[i][j]) p ++;
      S_[i][j] = p;
      if (p == n) a += S[i][j];
    }
  }
  for (int i = 0; i < N; i ++) {
    if (S_[0][i] != S_[1][i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

