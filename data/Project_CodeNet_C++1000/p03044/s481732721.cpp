#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<pair<int, int>>>;
//vector <int> d;

// 二部グラフ判定
vector<int> color;
void dfs(const Graph &G,int v,int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v.first] != -1) {
         
            //if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }else{
          if(next_v.second%2==0)
            dfs(G,next_v.first,cur);
          else
            dfs(G,next_v.first,1-cur);
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
       // if (!dfs(G, next_v , 1 - cur)) return false;
    }
    //return true;
}

int main(){

  int n,a,b,c;
  cin >> n;
   Graph G(n);

  //cout << "a" << endl;
  rep(i,n-1){
    cin >> a >> b >> c;
    pair<int, int> p(a-1,c);
    //cout << "a" << endl;
    G[b-1].push_back(p);
    p.first=b-1;
    G[a-1].push_back(p);
    //cout << "a" << endl;
  }
  //cout << "a" << endl;
   // 探索
    color.assign(n, -1);
   
    for (int v = 0; v < n; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        dfs(G, v);
    }
//cout << "a" << endl;
  rep(i,n)
    cout << color.at(i) << endl;
}