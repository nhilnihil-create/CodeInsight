#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int ans[510][510];
int main(){
  int n,m,q;
  cin >> n >> m >> q;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    ans[a][b]++;
  }
  rep(i,502){
    rep(j,502)ans[i][j + 1] += ans[i][j];
  }
  rep(i,q){
    int a,b;
    cin >> a >> b;
    int sum = 0;
    REP(j,a,b + 1)sum += ans[j][b] - ans[j][a - 1];
    cout << sum << endl; 
  }
  return 0;
}
