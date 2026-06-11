#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S;
  cin >> N >> S;
  int w = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '#') {
      b++;
    }
    else {
      w++; 
    }
  }
  int answer = min(N - b, N - w), B = b, W = w;
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i) == '#') {
      b--;
    }
    else{
      w--; 
    }
    answer = min(answer, B - b + w);
  }
  cout << answer << endl;
}