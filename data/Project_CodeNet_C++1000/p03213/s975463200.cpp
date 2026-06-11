#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int N, Prime[105], ans = 0;

int main(){
  cin >> N;
  for (int i = 2; i <= N; i++){
    int num = i;
    for (int j = 2; j <= i; j++){
      while (num % j == 0){
        Prime[j]++; num /= j; 
      }
    }
  }

  for (int i = 2; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      for (int k = 2; k <= N; k++){
        if (i == j || j == k || k == i) continue;
        int I = min(5, Prime[i] + 1);
        int J = min(5, Prime[j] + 1);
        int K = min(3, Prime[k] + 1);
        if (I * J * K == 75) ans++;
      }
    }
  }

  for (int i = 2; i <= N; i++){
    for (int j = 2; j <= N; j++){
      if (i == j) continue;
      int I = min(25, Prime[i] + 1);
      int J = min(3, Prime[j] + 1);
      if (I * J == 75) ans++;

      I = min(15, Prime[i] + 1);
      J = min(5, Prime[j] + 1);
      if (I * J == 75) ans++;
    }
  }

  for (int i = 2; i <= N; i++){
    if (Prime[i] >= 74) ans++;
  }

  cout << ans << endl;


  return 0;
}
