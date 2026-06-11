#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  if (N == 2) cout << S << endl;
  else cout << S[2] << S[1] << S[0] << endl;
}