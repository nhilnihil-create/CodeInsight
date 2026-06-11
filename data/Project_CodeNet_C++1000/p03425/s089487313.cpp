#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll nCr(ll n, ll r){
  if(n == r) return 1;
  if(n-r < r) r = n-r;
  if(r == 0) return 0;
  if(r == 1) return n;
  ll res = 1;
  for(ll i = 1; i <= r; i++){
    res *= n--;
    res /= i;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> cnt(5, 0);
  REP(i, N){
    string S; cin >> S;
    if(S[0] == 'M') cnt[0]++;
    if(S[0] == 'A') cnt[1]++;
    if(S[0] == 'R') cnt[2]++;
    if(S[0] == 'C') cnt[3]++;
    if(S[0] == 'H') cnt[4]++;
  }
  ll res = 0;
  for(int i = 0; i < 3; i++){
    for(int j = i+1; j < 4; j++){
      for(int k = j+1; k < 5; k++){
        res += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << res << endl;
}