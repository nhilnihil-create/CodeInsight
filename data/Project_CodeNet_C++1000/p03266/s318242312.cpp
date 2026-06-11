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
  ll N, K; cin >> N >> K;
  ll X = 0, Y = 0, Z = 0;
  for(ll i = 1; i <= N; i++){
    if(i%K == 0) X++;
    if(i%K == K/2 && K%2 == 0) Y++;
  }
  cout << X*X*X+Y*Y*Y << endl;
}
