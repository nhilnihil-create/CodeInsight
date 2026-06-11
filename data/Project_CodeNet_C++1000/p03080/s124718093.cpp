#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,count=0; cin >> N;
  string S;
  for(int i=0; i<N; i++) {
    cin >> S;
    if(S[i]=='R') count++;
    if(S[i]=='B') count--;
  }
  
  if(count <= 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}