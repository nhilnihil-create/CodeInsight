#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  string input;
  cin >> input;

  for(int i=0; i<N; i++) {
    if(i == K-1) cout << (char)tolower(input.at(i));
    else cout << (char)input.at(i);
  }

  cout << endl;
  return 0;
}

