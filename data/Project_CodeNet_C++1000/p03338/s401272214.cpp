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
  string S; cin >> S;
  
  int ans = 0;
  
  rep(i, N-1) {
    string X = S.substr(0, i+1);
    string Y = S.substr(i+1, N-i-1);
    
    unordered_map<char,int> xmap, ymap;
    
    rep(j, X.size()) xmap[X[j]]++;
    rep(j, Y.size()) ymap[Y[j]]++;
    
    int a = 0;
    
    for(auto p : xmap) if(ymap[p.first] > 0) a++;
    
    ans = max(ans, a);
  }
  
  cout << ans << endl;
  

}
