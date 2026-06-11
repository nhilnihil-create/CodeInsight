#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  int m=S[K-1];
  m+='a'-'A';
  S[K-1] = (char)m;
  cout << S << endl;
}
