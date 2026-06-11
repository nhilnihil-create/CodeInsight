#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> blue(N);
  for(int i = 0; i < N; i++) cin >> blue.at(i);
  int M;
  cin >> M;
  vector<string> red(M);
  for(int i = 0; i < M; i++) cin >> red.at(i);

  int sum = 0;
  for(int i = 0; i < N; i++) {
    string s = blue.at(i);
    if(s == "") continue;

    int b = 0;
    for(int j = 0; j < N; j++) {
      if(blue.at(j) == s) {
        blue.at(j) == "";
        b++;
      }
    }
    
    for(int j = 0; j < M; j++) {
      if(red.at(j) == s) b--;
    }
    
    if(b > sum) sum = b;
  }
  
  cout << sum << endl;
}
