#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  vector<int> t(3);
  rep(i,3) cin >> t[i];
  
  sort(t.begin(), t.end());
   
  cout << t[2]-t[1] + t[1]-t[0] << endl;
  
}
