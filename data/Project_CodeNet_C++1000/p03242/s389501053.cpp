#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  if(n[0]=='1') n[0]='9';
  else n[0]='1';
  if(n[1]=='1') n[1]='9';
  else n[1]='1';
  if(n[2]=='1') n[2]='9';
  else n[2]='1';
  cout << n << endl;
}