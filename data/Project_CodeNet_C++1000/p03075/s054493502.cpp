#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  vector<int> a(5);
  rep(i,5) cin >> a[i];
  
  int k;
  cin >> k;
  
  sort(a.begin(), a.end());
  
  bool ans = true;
  
  rep(i,4) {
    if(a[4] - a[i] > k) ans = false;
  }
  
  cout << (ans ? "Yay!" : ":(") << endl;
  
}
