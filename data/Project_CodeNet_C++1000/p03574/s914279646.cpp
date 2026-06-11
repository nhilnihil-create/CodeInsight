#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(g[i][j] == '#') continue;
      int cnt = 0;
      for(int k = -1; k < 2; k++){
        for(int l = -1; l < 2; l++){
          if(k == 0 && l == 0) continue;
          if(i+k < 0 || i+k > h-1 || j+l<0 || j+l>w-1) continue;
          if(g[i+k][j+l] == '#') cnt++;
        }
      }
      g[i][j] = cnt + '0';
    }
  }

  rep(i,h) cout << g[i] << endl;

}
