#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll INF = 1e16;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll A, B, Q; cin >> A >> B >> Q;
  vector<ll> a(A), b(B), q(Q);
  REPLL(i, A) cin >> a[i];
  REPLL(i, B) cin >> b[i];
  REPLL(i, Q) cin >> q[i];
  REPLL(i, Q){
    ll ans = INF;
    ll x = q[i];
    ll AF, AB, BF, BB;
    auto itrA = lower_bound(a.begin(), a.end(), x);
    if(itrA == a.end()){
      AF = INF;
    }else{
      AF = *itrA - x;
    }
    if(itrA-a.begin() == 0){
      AB = INF;
    }else{
      itrA--;
      AB = x - *itrA;
    }
    
    auto itrB = lower_bound(b.begin(), b.end(), x);
    if(itrB == b.end()){
      BF = INF;
    }else{
      BF = *itrB - x;
    }
    if(itrB-b.begin() == 0){
      BB = INF;
    }else{
      itrB--;
      BB = x - *itrB;
    }
    
    ans = min(ans, max(AF, BF));
    ans = min(ans, max(AB, BB));
    ans = min(ans, 2*AF+BB);
    ans = min(ans, 2*BB+AF);
    ans = min(ans, 2*AB+BF);
    ans = min(ans, 2*BF+AB);
    
    cout << ans <<endl;
  }
}
