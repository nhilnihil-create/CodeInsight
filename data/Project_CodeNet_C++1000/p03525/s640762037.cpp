#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi d(n); rep(i,n) cin >> d[i];
  sort(all(d));
  multiset<int> st{0};
  rep(i,n){
    if(i%2) st.insert(d[i]);
    else st.insert(24-d[i]);
  }
  int ans = INF;
  for(auto i = st.begin(); i != st.end(); i++) {
    for(auto j = st.begin(); j != st.end(); j++) {
      if(i == j) continue;
      chmin(ans, min(abs(*j-*i), 24+*i-*j));
    }
  }
  cout << ans << endl;
  return 0;
}
