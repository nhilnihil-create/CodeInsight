#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;

  for(int i = 0; i < s.size(); i++) {
    for(int j = s.size()-1; j >= i+1; j--)
      if(s[j] < s[j-1]) swap(s[j],s[j-1]);
  }
  for(int i = 0; i < t.size(); i++) {
    for(int j = t.size()-1; j >= i+1; j--)
      if(t[j] > t[j-1]) swap(t[j],t[j-1]);
  }
  if(s < t)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}