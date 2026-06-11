#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  if (S.at(K - 1) == 'A') {
    S.at(K - 1) = 'a';
  }
  if (S.at(K - 1) == 'C') {
    S.at(K - 1) = 'c';
  }
  if (S.at(K - 1) == 'B') {
    S.at(K - 1) = 'b';
  }
  cout << S << endl;
}