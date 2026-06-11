#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> prime(int N) {
  vector<bool> a(N, true);
  for(int i=1; i<sqrt(N); i++) {
    if(a[i]) for(int k=2; (i+1)*k-1<N; k++) a[(i+1)*k-1] = false;
  }
  vector<int> p;
  rep(i, N) if(a[i]) p.push_back(i+1);
  p.erase(p.begin());
  return p;
}

signed main() {
  int Q; cin >> Q;
  vector<int> p = prime(100000);
  
  unordered_map<int,int> m;
  for(int n : p) m[n]++;
  
  vector<int> v(100000, 0);
  rep(i, 100000-1) {
    v[i+1] = v[i];
    if(m[i+1] > 0 && m[(i+2)/2] > 0) v[i+1]++;
  }
  
  rep(i, Q) {
    int l, r; cin >> l >> r;
    cout << v[r] - v[l-1] << endl;
  }
    

}