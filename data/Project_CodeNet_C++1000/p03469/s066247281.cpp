#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  vector<char> t(10);
  rep(i,10) cin >> t[i];
  
  t[3] = '8';
  
  rep(i,10) cout << t[i];
  cout << endl; 
  
}
