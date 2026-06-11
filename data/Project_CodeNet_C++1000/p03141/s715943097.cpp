#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> A(N, 0);
  vector<ll> B(N, 0);
  vector<pair<ll, ll> > AB(N, pair<ll, ll>());
  REP(i, N){
    ll a, b; cin >> a >> b;
    A[i] = a; B[i] = b;
    AB[i] = {a + b, i};
  }
  sort(AB.begin(), AB.end(), greater<pair<ll, ll> >());
  ll a = 0, b = 0;
  for(ll i = 0; i < N - 1; i += 2){
    a += A[AB[i].second];
    b += B[AB[i+1].second];
  }
  if(N % 2 != 0){
    a += A[AB[N-1].second];
  }
  cout << a - b << endl;
}