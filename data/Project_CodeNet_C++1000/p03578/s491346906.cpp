#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main() {
  int N;cin >> N; map<ll, ll> A;
  rep(i,N){
    ll a;cin >> a;
    A[a]++;
  }
  int M;cin >> M;map<ll, ll> B;
  rep(i, M){
    ll b; cin >> b;B[b]++;
  }
  if (N < M) {
    cout << "NO" << endl;
    return 0;
  }
  bool judge;
  for (auto p : B){
    ll value = p.second;
    if (A[p.first] >= value) judge = 1;
    else {
      judge = 0;
      break;
    }
  }
  if (judge) cout << "YES" << endl;
  else cout << "NO" << endl;
}