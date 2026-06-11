#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int n,m;
  int p[100001], y[100001];

  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> p[i] >> y[i];

  vector<vector<int>> pre(100001);
  for(int i = 0; i < m; i++) pre[p[i]-1].push_back(y[i]);

  for(int i = 0; i < n; i++){
    sort(pre[i].begin(), pre[i].end());
  }

  // for(int i = 0; i < m; i++){
  //   for(auto a : pre[i]) cout << a << ',';
  //   cout << endl;
  // }

  for(int i = 0; i < m; i++){
    int v = p[i] - 1;
    // for(auto a : pre[i]) cout << a << endl;
    printf("%06d", v+1);

    int id = lower_bound(pre[v].begin(), pre[v].end(), y[i]) - pre[v].begin();
    printf("%06d\r\n", id+1);
  }



  return 0;
}