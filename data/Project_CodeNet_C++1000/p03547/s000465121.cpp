#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  if ( s<t ) puts("<");
  if ( s>t ) puts(">");
  if ( s==t ) puts("=");
  return 0; 
}