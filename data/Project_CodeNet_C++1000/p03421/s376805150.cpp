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

ll N, A, B;
bool visited[int(3e5 + 5)];
int ans[int(3e5 + 5)];

int main(){
  cin >> N >> A >> B;
  if (A * B < N || A + B - 1 > N){
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= A; i++){
    ans[i] = N - A + i;
    visited[N - A + i] = true;
  }

  int now = A + 1, num = 0;
  while (now <= N){
    num += B - 1;
    num = min(num, (int)(N - A));

    for (int i = 0; i < B - 1; i++){
      if (num - i <= 0) break;
      if (now > N) break;
      ans[now] = num - i;
      visited[num - i] = true;
      now++;
    }
  }

  cout << ans[1];
  for (int i = 2; i <= N; i++) cout << " " << ans[i];
  cout << endl;

  return 0;
}
