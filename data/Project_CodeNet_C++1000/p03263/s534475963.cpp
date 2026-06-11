#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>>a(h,vector<int>(w));
  vector<vector<int>>ans(h*w,vector<int>(4));
  rep(i,0,h) rep(j,0,w) cin >> a[i][j];
  int c = 0;
  rep(i,0,h){
    if(i%2 == 0){
      rep(j,0,w){
        if(a[i][j]%2 == 0) continue;
        if(j != w-1){
          ans[c][0] = i;
          ans[c][1] = j;
          ans[c][2] = i;
          ans[c][3] = j+1;
          a[i][j+1]++;
        }
        else{
          if(i == h-1) break;
          ans[c][0] = i;
          ans[c][1] = j;
          ans[c][2] = i+1;
          ans[c][3] = j;
          a[i+1][j]++;
        }
        c++;
      }
    }
    else{
      for(int j = w-1;j >= 0;j--){
        if(a[i][j]%2 == 0) continue;
        if(j != 0){
          ans[c][0] = i;
          ans[c][1] = j;
          ans[c][2] = i;
          ans[c][3] = j-1;
          a[i][j-1]++;
        }
        else{
          if(i == h-1) break;
          ans[c][0] = i;
          ans[c][1] = j;
          ans[c][2] = i+1;
          ans[c][3] = j;
          a[i+1][j]++;
        }
        c++;
      }
    }
  }
  cout << c << endl;
  rep(i,0,c) cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans[i][2]+1 << " " << ans[i][3]+1 << endl;
}