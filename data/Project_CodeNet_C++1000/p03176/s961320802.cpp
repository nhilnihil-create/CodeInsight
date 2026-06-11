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

struct SegmentTree{
  int N;
  vector <ll> Table[20];
  void Make(){
    for (int i = 0; i < 20; i++){
      Table[i].resize((1<<i));
    }
    return;
  }

  ll Search(int num){
    int now = 19; ll ans = 0;
    while (num > 0){
      if (num % 2 == 0){
        now--; num = num / 2 - 1;
        ans = max(ans, Table[now][num]);
      }else{
        num--;
        ans = max(ans, Table[now][num]);
      }
    }
    return ans;
  }

  void Add(int num, ll val){
    for (int i = 19; i >= 0; i--){
      Table[i][num] = max(Table[i][num], val);
      num /= 2;
    }
  }
};

int N, H[int(2e5+5)];
ll A[int(2e5+5)];

int main(){
  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i];
  for (int j = 0; j < N; j++) cin >> A[j];

  SegmentTree T; T.N = N;
  T.Make();

  for (int i = 0; i < N; i++){
    ll now = A[i] + T.Search(H[i]);
    T.Add(H[i], now);
  }
  cout << T.Table[0][0] << endl;

  return 0;
}
