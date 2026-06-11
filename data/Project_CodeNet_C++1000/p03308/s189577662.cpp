#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  int ab = 0;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    rep(j,n){
      ab = max(ab,abs(a[i] - a[j]));
    }
  }
  cout << ab << endl;
}