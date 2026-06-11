#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC081 D - Non-decreasing
// 2020.06.24

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<ll> a(N);
  ll M = -1e9, m = 1e9;
  int Midx = 0, midx = 0;
  REP(i, N){
    cin >> a[i];
    M = max(M, a[i]);
    if(M == a[i]) Midx = i;
    m = min(m, a[i]);
    if(m == a[i]) midx = i;
  }
  if(m >= 0){
    cout << N-1 << endl;
    REP(i, N-1){
      cout << i+1 << " " << i+2 << endl;
    }
    return 0;
  }
  if(M <= 0){
    cout << N-1 << endl;
    REP(i, N-1){
      cout << N-i << " " << N-i-1 << endl;
    }
    return 0;
  }
  if(M >= abs(m)){
    cout << 2*N-1 << endl;
    REP(i, N){
      cout << Midx+1 << " " << i+1 << endl;
    }
    REP(i, N-1){
      cout << i+1 << " " << i+2 << endl;
    }
    return 0;
  }else{
    cout << 2*N-1 << endl;
    REP(i, N){
      cout << midx+1 << " " << i+1 << endl;
    }
    REP(i, N-1){
      cout << N-i << " " << N-i-1 << endl;
    }
    return 0;
  }
}