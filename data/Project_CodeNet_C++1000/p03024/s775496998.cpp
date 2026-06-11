#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int sum=0;
  for(int i=0; i<S.size(); i++) {
    if(S.at(i)=='x') sum += 1;
  }
  if(sum>=8) cout << "NO" << endl;
  else cout << "YES" << endl;
}