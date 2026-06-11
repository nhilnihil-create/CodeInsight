#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<string, int> mp;
  int N; cin >> N;
  REP(i, N){
    string S; cin >> S;
    mp[S]++;
  }
  int M; cin >> M;
  REP(i, M){
    string S; cin >> S;
    mp[S]--;
  }
  int ans = 0;
  for(auto i : mp){
    ans = max(ans, i.second);
  }
  cout << ans << endl;
}
