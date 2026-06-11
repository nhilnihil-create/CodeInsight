#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<char> S(N);
  K--;
  for(int i = 0; i < N; i++) {cin >> S.at(i);}
  if (S.at(K) == 'A') {S.at(K) = 'a';}
  else if (S.at(K) == 'B') {S.at(K) = 'b';} 
  else if (S.at(K) == 'C') {S.at(K) = 'c';}
  else if (S.at(K) == 'D') {S.at(K) = 'd';}
  else if (S.at(K) == 'E') {S.at(K) = 'e';}
  else if (S.at(K) == 'F') {S.at(K) = 'f';}
  else if (S.at(K) == 'G') {S.at(K) = 'g';}
  else if (S.at(K) == 'H') {S.at(K) = 'h';}
  else if (S.at(K) == 'I') {S.at(K) = 'i';}
  else if (S.at(K) == 'J') {S.at(K) = 'j';}
  else if (S.at(K) == 'K') {S.at(K) = 'k';}
  else if (S.at(K) == 'L') {S.at(K) = 'l';}
  else if (S.at(K) == 'M') {S.at(K) = 'm';}
  else if (S.at(K) == 'N') {S.at(K) = 'n';}
  else if (S.at(K) == 'O') {S.at(K) = 'o';}
  else if (S.at(K) == 'P') {S.at(K) = 'p';}
  else if (S.at(K) == 'Q') {S.at(K) = 'q';}
  else if (S.at(K) == 'R') {S.at(K) = 'r';}
  else if (S.at(K) == 'S') {S.at(K) = 's';}
  else if (S.at(K) == 'T') {S.at(K) = 't';}
  else if (S.at(K) == 'U') {S.at(K) = 'u';}
  else if (S.at(K) == 'V') {S.at(K) = 'v';}
  else if (S.at(K) == 'W') {S.at(K) = 'w';}
  else if (S.at(K) == 'X') {S.at(K) = 'x';}
  else if (S.at(K) == 'Y') {S.at(K) = 'y';}
  else {S.at(K) = 'z';}
  for (int i = 0; i < N; i++) {cout << S.at(i);}
}