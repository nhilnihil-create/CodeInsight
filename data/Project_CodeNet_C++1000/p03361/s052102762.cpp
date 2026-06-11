#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

 // 深さ優先探索
vector<bool> seen;
int dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    int score = 0; 

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        // 負荷さ優先探索中の処理



        dfs(G, next_v); // 再帰的に探索, 毎回mat渡してええの？
    }
    return score;
} 

/*
//桁数の計算
ll keta(ll num){
  ll ans= 0 ;
  ll rem;

  for (ll i = 4; i >= 0 ; i--){
    rem = pow(10,i);
    ans += (num / rem); 
    num = num % rem;
  }
  return ans;
}
*/


int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));

    for (ll i =0; i<H; i++){
      for (ll j =0; j<W; j++){
        cin >> s[i][j];
      }
    }
    vector<int> dx = {0,-1,1,0};
    vector<int> dy = {-1,0,0,1};

    for (ll i =0; i<H; i++){
      for (ll j =0; j<W; j++){
        if(s[i][j] == '#'){
          bool flag = false;
          for(ll d=0; d<4; d++){
            ll x = i + dx[d];
            ll y = j + dy[d];

            if (x < 0 || x>=H) continue;
            if (y < 0 || y>=W) continue;

            if(s[x][y] == '#') flag = true;
          }
          if (!flag) {
            cout << "No" << endl;
            //cout << i << endl;
            //cout << j << endl;
            goto end;

          }
        }
      }
    }

    cout << "Yes" << endl;
    end:
    return 0;
}