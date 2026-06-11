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

int N, M, ans;
vector <int> Prime;

int Judge(){
  for (int i = 1; i * i <= M; i++){
    if (M % i == 0){
      Prime.push_back(i);
      Prime.push_back(M / i);
    }
  }
  return 0;
}


int main(){
  cin >> N >> M;
  Judge();

  for (int i = 0; i < Prime.size(); i++){
    int P = Prime[i];
    if (M / P >= N){
      ans = max(P, ans);
    }
  }
  cout << ans << endl;

  return 0;
}
