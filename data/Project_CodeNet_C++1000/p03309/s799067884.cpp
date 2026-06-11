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

  vl B(N);
  rep(i, N) B[i] = A[i] - (i + 1);

  stable_sort(B.begin(), B.end());

  if(N % 2 == 1){
    ll ans = 0;
    ll b = B[N / 2];

    rep(i, N) ans += abs(B[i] - b);

    cout << ans << "\n";
  } else{
    if((B[N / 2 - 1] + B[N / 2]) % 2 == 0){
      ll b = (B[N / 2 - 1] + B[N / 2]) / 2;
      ll ans = 0;

      rep(i, N) ans += abs(B[i] - b);

      cout << ans << "\n";
    } else{
      ll b1 = B[N / 2 - 1], b2 = B[N / 2];
      ll ans1 = 0, ans2 = 0;

      rep(i, N){
        ans1 += abs(B[i] - b1);
        ans2 += abs(B[i] - b2);
      }

      cout << min(ans1, ans2) << "\n";
    }
  }
  
  return 0;
}
