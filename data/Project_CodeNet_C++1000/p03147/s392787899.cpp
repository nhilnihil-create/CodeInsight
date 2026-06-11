#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  
  vi h(n+2);
  REP(i,1,n+1) cin >> h.at(i);
  h.at(0) = 0;
  h.at(n+1) = 0;
  
  int ans = 0;
  rep(i,1'000'0){
    int flag = 0;
    rep(j,n+2){
      if (flag == 0 && h.at(j) > 0){
        flag = 1;
        h.at(j)--;
      }
      else if (flag == 1 && h.at(j) == 0){
        flag = 0;
        ans++;
      }
      else if (flag == 1){
        h.at(j)--;
      }
    }
    /*rep(j,n+2){
      printf("%2d ", h.at(j));
    }
    printf("ans = %d", ans);
    cout << endl;*/
    int cnt = 0;
    rep(j,n+2){
      if (h.at(j) == 0){
        cnt++;
      }
    }
    if (cnt == n+2){
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
