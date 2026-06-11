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

int cnt[int(1e5+5)];

bool Prime(int num){
  if (num == 1) return false;
  for (int i = 2; i * i <= num; i++){
    if (num % i == 0) return false;
  }
  return true;
}

int main(){
  for (int i = 1; i <= int(1e5); i++){
    cnt[i] = cnt[i-1];
    if (Prime(i) && Prime((i+1)/2) && i%2!= 0) cnt[i]++;
  }

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++){
    int L, R; cin >> L >> R;
    cout << cnt[R] - cnt[L - 1] << endl;
  }


  return 0;
}
