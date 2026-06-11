#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int v[1000][1000],ans[10000][4];
int main(){
  int h,w;
  cin >> h >> w;
  rep(i,h)rep(j,w)cin >> v[i][j];
  int N = 0;
  rep(i,h - 1)rep(j,w){
    if(v[i][j] % 2 != 0){
      v[i + 1][j]++,v[i][j]--;
      ans[N][0] = i + 2,ans[N][1] = j + 1,ans[N][2] = i + 1,ans[N][3] = j + 1;
      swap(ans[N][0],ans[N][2]);
      swap(ans[N][1],ans[N][3]);
      N++;
    }
  }
  rep(i,w - 1)if(v[h - 1][i] % 2 != 0){
    v[h - 1][i + 1]++,v[h - 1][i]--;
    ans[N][0] = h,ans[N][1] = i + 1,ans[N][2] = h,ans[N][3] = i + 2;
    N++;
  }
  cout << N << endl;
  rep(i,N)cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
  return 0;
}
