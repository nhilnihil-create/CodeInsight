#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  sort(s.begin(),s.end());
  if(s == "abc")
    cout << "Yes" << endl;
  else cout << "No" << endl;
}