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

int main(){
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];

  stable_sort(A.begin(), A.end());

  cout << A[N - 1] - A[0] << "\n";
  
  return 0;
}
