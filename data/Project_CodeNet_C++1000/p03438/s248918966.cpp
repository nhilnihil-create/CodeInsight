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
  int N; cin >> N;
  vector<ll> a(N), b(N);
  ll A = 0, B = 0;
  REP(i, N){
    cin >> a[i];
    A += a[i];
  }
  REP(i, N){
    cin >> b[i];
    B += b[i];
  }
  ll res = B - A;
  ll cntA = 0, cntB = 0;
  REP(i, N){
    if(a[i] > b[i]){
      cntB += a[i] - b[i];
    }else{
      cntA += (b[i]-a[i]+1)/2;
    }
  }
  if(res >= max(cntA, cntB)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}