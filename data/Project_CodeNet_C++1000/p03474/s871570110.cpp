#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  bool ok = true;
  rep(i,a) if (s[i]=='-') ok = false;
  if (s[a] != '-') ok = false;
  rep(i,b) if (s[i+a+1]=='-') ok = false;
  
  if (ok)
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
}