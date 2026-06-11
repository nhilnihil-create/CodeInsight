#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  int r = 2;
  vector<vector<int>> a(r,vector<int>(n));
  rep(i,r){
    rep(j,n) cin >> a[i][j];
  }

  int k = 4;
  vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
  int ans = -1;
  int x = 0,y = 0;
  int cnt = 0;
  while(1){
    int tmp = a[0][0];
    int j=0;
    if(cnt == 0){
      rep(i,n){
	if(i==cnt) j++;

	tmp += a[j][i];
      }      
    }
    
    else{
      for(int i = 1;i<n;i++){
	if(i==cnt){
	  tmp += a[j][i];
	  j++;
	}

	tmp += a[j][i];
      }
    }
    ans = max(ans,tmp);
    cnt++;
    if(cnt==n) break;
  }

  cout << ans << endl;
    
  return 0;
}
