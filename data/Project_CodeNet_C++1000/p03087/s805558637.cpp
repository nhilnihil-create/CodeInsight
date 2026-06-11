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
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<int> cnt(N, 0);
  REP(i, N-1){
    if(S[i] == 'A' && S[i+1] == 'C'){
      cnt[i+1] = cnt[i] + 1;
    }else{
      cnt[i+1] = cnt[i];
    }
  }
  REP(i, Q){
    int l, r; cin >> l >> r; l--; r--;
    int ans = cnt[r]-cnt[l];
    cout << ans << endl;
  }
}