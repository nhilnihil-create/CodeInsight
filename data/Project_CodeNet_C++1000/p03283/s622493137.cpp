#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int v[505][505];
int s[505][505];
int main() {
  int n,m,q;
  cin >> n >> m >> q;
  rep(i,m){
    int l,r;
    cin >> l >> r;
    v[l][r]++;
  }
  rep(i,n)rep(j,n) s[i+1][j+1] = s[i+1][j] + v[i+1][j+1];
  
  rep(qi,q){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; ++i){
      ans += s[i][b] - s[i][a-1];
    }
    cout << ans << endl;
  }
}