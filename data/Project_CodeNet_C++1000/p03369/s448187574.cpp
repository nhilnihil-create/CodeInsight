#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  string s;
  cin >> s;
  int count = 0;
  if(s[0]=='o') count++;
  if(s[1]=='o')count++;
  if(s[2]=='o') count++;
  cout << 700 + 100 * count << endl;
}