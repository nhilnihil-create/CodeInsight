#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N,K;

int main() {
  cin >> N >> K;

  map<int, int> mp;
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i,N) {
    int a;
    cin >> a;
    mp[a]++;
  }

  if (mp.size() <= K) {
    cout << 0 << endl;
    return 0;
  }


  int sum = 0;
  int b = mp.size() - K;
  vector<int> v;
  for(auto iter = mp.begin(); iter != mp.end(); iter++){
    v.push_back(iter->second);
  }
  sort(v.begin(),v.end());
  int ans = 0;
  rep(i,b){
    ans += v[i];
  }
  cout << ans << endl;




	return 0;
}

