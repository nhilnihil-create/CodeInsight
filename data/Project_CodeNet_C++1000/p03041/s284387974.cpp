#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  int K, N;
  cin >> N >> K >> S;
  K--;
  if (S.at(K) == 'A')S.at(K) = 'a';
  if (S.at(K) == 'B')S.at(K) = 'b';
  if (S.at(K) == 'C')S.at(K) = 'c';
  cout << S << endl;
}