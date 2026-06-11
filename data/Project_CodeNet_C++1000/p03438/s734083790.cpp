#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> a(N), b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  
  int k = 0;
  rep(i, N) {
    if(a[i] > b[i]) k -= a[i]-b[i];
    if(a[i] < b[i]) k += (b[i]-a[i])/2;
  }
  
  if(k >= 0) cout << "Yes" << endl;
  else cout << "No" << endl;

}