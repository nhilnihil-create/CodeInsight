#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl A(N + 2, 0);
  ll tot = 0;
  rep2(i, 1, N + 1){
    cin >> A[i];
    tot += abs(A[i - 1] - A[i]);
  }
  tot += abs(A[N] - A[N + 1]);

  rep2(i, 1, N + 1) cout << tot - abs(A[i - 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]) << endl;
  
  return 0;
}
