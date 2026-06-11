#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int N, M, Q, X[501][501], C[501][501];
int L, R;
int p, q;

int main(){
  cin >> N >> M >> Q;
  rep (i, M){
    cin >> L >> R;
    X[L][R] += 1;
  }
  rep (i, N){
    rep(j, N){
      C[i][j] = C[i][j-1] + X[i][j];
    }
  }
  rep (i, Q){
    cin >> p >> q;
    int ans = 0;
    for (int j = p ; j <= q; j++){
      ans += C[j][q]-C[j][p-1];
    }
    cout << ans << endl;
  }
}
