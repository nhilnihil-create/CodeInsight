#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll GCD(ll A, ll B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B; swap(A, B);
  }
  return B;
}

int N;
ll A[int(1e5+5)];
ll L[int(1e5+5)], R[int(1e5+5)];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  L[0] = A[0];
  for (int i = 1; i < N; i++){
    L[i] = GCD(L[i-1], A[i]);
  }

  R[N-1] = A[N-1];
  for (int i = N - 2; i >= 0; i--){
    R[i] = GCD(R[i+1], A[i]);
  }

  ll ans = max(R[1], L[N - 2]);

  for (int i = 1; i < N - 1; i++){
    ans = max(ans, GCD(L[i-1], R[i+1]));
  }
  cout << ans << endl;

  return 0;
}
