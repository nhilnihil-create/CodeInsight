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

ll N; int ans;
int DFS(ll num, bool three, bool five, bool seven){
  if (num > N) return 0;

  if (three && five && seven) ans++;
  DFS(num*10+3, 1, five, seven);
  DFS(num*10+5, three, 1, seven);
  DFS(num*10+7, three, five, 1);

  return 0;
}

int main(){
  cin >> N;
  DFS(0,0,0,0);
  cout << ans << endl;

  return 0;
}
