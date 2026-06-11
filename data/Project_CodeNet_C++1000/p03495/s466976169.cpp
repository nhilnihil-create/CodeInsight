#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC081 C - Not so Diverse
// 2020.06.24

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  map<int, int> mp; 
  set<int> s;
  REP(i, N){
    int a; cin >> a;
    mp[a]++;
    s.insert(a);
  }
  int n = s.size();
  if(n <= K){
    cout << 0 << endl;
    return 0;
  }
  priority_queue<int, vector<int>, greater<int> > pq;
  int ans = 0;
  for(auto i : mp){
    pq.push(i.second);
  }
  REP(i, n-K){
    ans += pq.top(); pq.pop();
  }
  cout << ans << endl;
}