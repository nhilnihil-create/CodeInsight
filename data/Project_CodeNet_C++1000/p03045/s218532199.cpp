#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
int l[100005] = {};
vector<vector<int>> g(100005);

int bfs(int i){
  int tmp;
  int rm = g[i].size();
  for(int j= 0;j < rm ;j++){
    tmp = g[i][j];
    if(l[tmp] == 0){
      l[tmp] = 1;
      bfs(tmp);
    }
  }
  return 0;
}




int main() {
  int n,m;
  cin >> n >> m;
  int x,y,z;
  //int c = 1;
  for(int i= 0;i < m;i++){
    cin >> x >> y >> z;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int c = 0;
  for(int i = 1;i< n+1;i++){
    if(l[i] == 0){
      l[i] = 1;
      c++;
      bfs(i);
    }
  }
  cout << c;
}
