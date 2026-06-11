#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;

  int count = 0;

  for(int i=0; i<N; i++){
      if(S.at(i) == 'R') count++; else count--;
  }

  cout << (count > 0 ? "Yes" : "No") << endl;
  return 0;
}