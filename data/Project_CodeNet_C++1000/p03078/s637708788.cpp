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
  ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  REPLL(i, X) cin >> A[i];
  REPLL(i, Y) cin >> B[i];
  REPLL(i, Z) cin >> C[i];
  vector<ll> AB;
  REPLL(i, X){
    REPLL(j, Y){
      AB.push_back(A[i]+B[j]);
    }
  }
  sort(AB.begin(), AB.end(), greater<ll>());
  sort(C.begin(), C.end(), greater<ll>());
  priority_queue<ll> pq;
  ll idx1 = min(X*Y, K), idx2 = min(Z, K);
  REPLL(i, idx1){
    REPLL(j, idx2){
      pq.push(AB[i]+C[j]);
    }
  }
  ll cnt = 0;
  while(cnt < K){
    cout << pq.top() << endl;
    pq.pop();
    cnt++;
  }
}