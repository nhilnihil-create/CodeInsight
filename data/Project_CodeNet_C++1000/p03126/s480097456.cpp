#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  vector<int> food(m,0);
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      a--;
      food.at(a)++;
    }
  }
  int cnt = 0;
  for(int i = 0; i < m; i++){
    if(food.at(i) == n) cnt++;
  }
  cout << cnt;
}