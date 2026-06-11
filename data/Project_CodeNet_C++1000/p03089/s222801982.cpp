#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> s(vector<int> b, vector<int> a) {
  if(b.size() == 0) return a;
  bool k = false;
  for(int i=b.size()-1; i>=0; i--) {
    if(b[i]-1 == i) {
      k = true;
      vector<int> bb = b;
      bb.erase(bb.begin()+i);
      vector<int> aa = a;
      aa.push_back(i+1);
      return s(bb, aa);
      //if(ss.size() > 0) return ss;
    }
  }
  if(!k) return {};
}

signed main() {
  int N; cin >> N;
  vector<int> b(N);
  rep(i, N) cin >> b[i];
  
  vector<int> a = {};
  vector<int> ss = s(b, a);
  if(ss.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  reverse(all(ss));
  rep(i, N) cout << ss[i] << endl;
  
}
