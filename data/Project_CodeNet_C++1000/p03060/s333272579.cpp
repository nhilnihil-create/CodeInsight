#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
int V[30];
int C[30];

int main(){
  cin >> N;
  rep(i, N) cin >> V[i];
  rep(i, N) cin >> C[i];
  int ans = 0;
  rep(i, N){
    if (V[i] - C[i] > 0) ans += V[i] - C[i];
  }
  cout << ans << endl;
}
