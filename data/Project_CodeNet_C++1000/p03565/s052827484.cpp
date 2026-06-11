#include <bits/stdc++.h>
using namespace std;

string s, t;   //入力文字列
int S, T;      //文字列の長さ

bool match(int k) {
  for ( int i = 0; i < T; i++ ) {
    if ( t[i] != s[i+k] && s[i+k] != '?' ) {
      return false;
    }
  }
  return true;
}

string construct(int k) {
  string ans = s;
  for ( int i = 0; i < T; i++ ) {
    ans[k+i] = t[i];
  }
  for ( int i = 0; i < S; i++ ) {
    if ( ans[i] == '?' ) {
      ans[i] = 'a';
    }
  }
  return ans;
}

int main() {
  cin >> s >> t;
  S = s.length();
  T = t.length();
  
  int a = -1;
  for ( int i = 0; i <= S-T; i++ ) {
    if ( match(i) ) {
      a = i;
    }
  }
  string ANS = construct(a);
  
  if ( a == -1 ) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << ANS << endl;
  }
  
  return 0;
}