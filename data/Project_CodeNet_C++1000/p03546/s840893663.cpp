#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int H, W;
  cin >> H >> W;
  vector<vector<int>> vec(10, vector<int>(10));
  vector<vector<int>> tree(10, vector<int>(0));
  vector<int> mp(10);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if (i != j) {
        tree.at(i).push_back(j);
      }
    }
  }
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  for (int i = 0; i <= 9; i++) {
    if (i == 1) {
      continue;
    }
    vector<int> dist(10,-1);
    queue<int> que;
    que.push(i);
    dist.at(i) = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      if (v == 1) {
        continue;
      }
      for (int j = 0; j < (int) tree.at(v).size(); j++) {
        int nv = tree.at(v).at(j);
        if (dist.at(nv) != -1 && dist.at(nv) <= dist.at(v) + vec.at(v).at(nv)){
          continue;
        }
        //cout << v << " " << dist.at(v) << "   " << nv << " " << dist.at(nv) << endl;
        dist.at(nv) = dist.at(v) + vec.at(v).at(nv);
        que.push(nv);
      }
    }
    mp.at(i) = dist.at(1);
  }
  int answer = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      if (a == -1) {
        continue;
      }
      answer += mp.at(a);
    } 
  }
  cout << answer << endl;
}