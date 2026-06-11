#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  string s;
  cin >> s;
  sort(all(s));
  if(s == "abc") cout << "Yes" << endl;
  else cout << "No" << endl;
}