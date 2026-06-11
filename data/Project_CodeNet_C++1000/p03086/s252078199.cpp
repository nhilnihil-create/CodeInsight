#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,s1[20];
  cin >> s;

  int j = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T')     
      s1[j] += s[i];
    else {
      if(s1[j] == "") continue;
      else j++;
    }
  }
  int max = 0;
  for(int i = 0; i < 20; i++) {
    if(max < s1[i].size())
      max = s1[i].size();
  }
  cout << max << endl; 
}