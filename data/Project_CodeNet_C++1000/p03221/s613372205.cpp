#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  vector<vector<int>> vec(n+1);
  rep(i, m){
    cin >> p[i] >> y[i];
    vec[p[i]].push_back(y[i]);
  }
  rep2(i, 1, n+1){
    sort(vec[i].begin(), vec[i].end());
  }
  rep(i, m){
    auto itr = find(vec[p[i]].begin(), vec[p[i]].end(), y[i]);
    printf("%06d%06d\n", p[i], itr-vec[p[i]].begin()+1);
  }
  
  return 0;
}