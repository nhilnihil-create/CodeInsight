#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int x = (s[0]-'0')*10 + s[1]-'0';
  int y = (s[2]-'0')*10 + s[3]-'0';

  if(0<x & x<13) {
    if(0<y & y<13) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }
  else {
    if(0<y & y<13) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }  
}