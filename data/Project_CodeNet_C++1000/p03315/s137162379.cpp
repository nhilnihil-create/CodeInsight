#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int count =0;
  for(int i=0; i<4; i++) {
    cin >> S;
    if(S[i]=='+') count++;
    if(S[i]=='-') count--;
  }
  cout << count << endl;
}