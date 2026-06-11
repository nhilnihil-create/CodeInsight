#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    cin >> d[i];
  }

  int m; cin >> m;
  vector<int> t(m);
  for(int i = 0; i < m; i++){
    cin >> t[i];
  }

  multiset<int> st, st2;
  for(int i = 0; i < n; i++){
    st.insert(d[i]);
  }
  for(int i = 0; i < m; i++){
    st2.insert(t[i]);
  }

  for(auto p : st2){
    auto pos = st.find(p);
    if(pos == st.end()){
      cout << "NO" << endl;
      return 0;
    }
    st.erase(pos);
  }
  cout << "YES" << endl;

  return 0;
}