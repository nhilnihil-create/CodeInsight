#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,d,x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> cho(d +1,0);
  int cnt = 0;
  rep(i,n){
    rep(j,100){
      if(j*a[i] + 1 <= d)cnt++;
    }
  }
  cout << cnt + x << endl;
}