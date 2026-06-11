#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int H, W;
  cin >> H >> W;
  int a[H][W];
  rep(i, H){
    rep(j, W){
      cin >> a[i][j];
    }
  }
  int N = 0;
  vector <vector<int>>ans;
  rep(i, H){
    rep(j, W-1){
      if (a[i][j] % 2 == 1){
        a[i][j+1] ++;
        ans.push_back({i+1, j+1, i+1, j+2});
        N++;
      }
    }
  }
  rep(i, H-1){
    if (a[i][W-1] % 2 == 1){
      a[i+1][W-1] ++;
      ans.push_back({i+1, W, i+2, W});
      N ++;
    }
  }
  cout << N <<endl;
  rep(i, N){
    cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
  }
}
   