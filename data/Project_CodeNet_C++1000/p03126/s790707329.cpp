#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M;
int ANS[50];

int main(){
  cin >> N >> M;
  rep(i, N){
    int k;
    cin >> k;
    rep(j, k){
      int a;
      cin >> a;
      // 0インデックスに揃える
      a--;
      ANS[a]++;
    }
  }

  int ans = 0;
  rep(i, M){
    if (ANS[i]==N) ans++;
  }

  cout << ans << endl;
}
