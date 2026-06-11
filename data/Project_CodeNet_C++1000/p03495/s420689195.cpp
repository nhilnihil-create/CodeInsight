#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,k; cin>>n>>k;
  
  vector<int> v;
  map<int,int> mp;
  
  int res = 0;
  
  rep(i,n) {
    int a; cin>>a;
    
    ++mp[a];
  }
  
  for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
    v.push_back(iter->second);
  }
  
  sort(all(v));
    
  if(v.size() > k) {
    rep(i, v.size() - k) res += v[i];
  }
  
  cout<<res;

}