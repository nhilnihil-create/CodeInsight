#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<int> k(n);
  vector<vector<int>> a(n);
  rep(i,n){
    cin >> k[i];
    rep(j,k[i]){
      int in; cin >> in;
      a[i].push_back(in);
    }
  }

  int ans = 0;  
  rep(j,k[0]){
    int tmp = a[0][j];
    int num=0;
    for(int i = 1;i<n;i++){
      rep(h,k[i]){
	if(tmp==a[i][h]){
	  num++;
	  break;
	}
      }
    }
    if(num==n-1) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
