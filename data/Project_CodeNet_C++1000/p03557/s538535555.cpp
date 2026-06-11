#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60; 

ll N, A[100010], B[100010], C[100010];

int main()
{
  cin >> N;
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) cin >> C[i];
  
  sort(A, A+N);
  sort(B, B+N);
  sort(C, C+N);
  
  ll ans = 0;
  rep(i,N)
  {
    ll aj = lower_bound(A, A+N, B[i])-A;
    ll cj = upper_bound(C, C+N, B[i])-C;
    ans += aj*(N-cj);
  }
  cout << ans << endl;
}