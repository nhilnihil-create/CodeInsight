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
  unordered_map<int,int> D;
  rep(i, N) {
    int d; cin >> d;
    D[d]++;
  }
  int M; cin >> M;
  vector<int> T(M);
  rep(i, M) cin >> T[i];
  
  rep(i, M) {
    if(D[T[i]] > 0) {
      D[T[i]]--;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  
  
  

  
}
