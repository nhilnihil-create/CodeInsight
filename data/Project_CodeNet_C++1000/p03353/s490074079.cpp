#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  string s; cin >> s;
  int k; cin >> k;

  set<string> st;
  rep(i, s.size()){
    for(int j=1; j<=k && i+j<=s.size(); j++){
      st.insert(s.substr(i, j));
    }
  }

  auto itr = st.begin();
  if(k>1) rep(i, k-1) ++itr;
  
  cout << *itr << endl;

  return 0;
}
