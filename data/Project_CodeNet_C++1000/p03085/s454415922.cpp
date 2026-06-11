#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  char c;
  cin >> c;
  if(c=='A') cout << 'T';
  if(c=='T') cout << 'A';
  if(c=='C') cout << 'G';
  if(c=='G') cout << 'C';
  return 0;
}