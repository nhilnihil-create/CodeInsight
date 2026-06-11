#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC106 D-AtCoder Express2
// 2020.06.07
// 二次元累積和、包除原理

ll N, M, Q;
vector<vector<ll> > A;
vector<vector<ll> > AA;

ll func(ll l, ll r){
  ll res = 0;
  res += AA[r][r];
  if(l != 0){
    res -= AA[l-1][r];
    res -= AA[r][l-1];
    res += AA[l-1][l-1];
  } 
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> Q;
  A.assign(N, vector<ll>(N, 0));
  AA.assign(N, vector<ll>(N, 0));
  REP(i, M){
    ll L, R; cin >> L >> R; L--; R--;
    A[L][R]++;
  }
  REP(i, N){
    REP(j, N){
      if(i == 0){
        if(j == 0){
          AA[i][j] = A[i][j];
        }else{
          AA[i][j] = AA[i][j-1] + A[i][j];
        }
      }else{
        if(j == 0){
          AA[i][j] = AA[i-1][j] + A[i][j];
        }else{
          AA[i][j] = AA[i][j-1] + AA[i-1][j] - AA[i-1][j-1] + A[i][j];
        }
      }
    }
  }
  REP(i, Q){
    ll p, q; cin >> p >> q; p--; q--;
    cout << func(p, q) << endl;
  }
}