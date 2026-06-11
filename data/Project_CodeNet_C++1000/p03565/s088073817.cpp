#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

void leave(string message) {
  cout << message << endl;
  exit(0);
}

bool eq(string x, string y) {
  lint n = x.length();
  lint m = y.length();
  if(n != m) return false;
  bool res = true;
  for(lint i=0; i<n; i++) {
    res &= (x[i] == y[i]) || (x[i] == '?');
  }
  return res;
}

int main() {
  string S, T;
  cin >> S >> T;

  lint N = S.length();
  lint M = T.length();
  lint ans = -1;
  for(lint i=0; i<N; i++) {
    if(eq(S.substr(i,M), T)) ans = i;
  }

  if(ans == -1) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  for(lint i=ans; i<ans+M; i++) S[i] = T[i-ans];
  for(lint i=0; i<N; i++) if(S[i] == '?') S[i] = 'a';
  
  cout << S << endl;
}