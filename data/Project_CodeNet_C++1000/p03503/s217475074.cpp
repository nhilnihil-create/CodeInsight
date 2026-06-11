#include<bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main(){
  int n; cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  vector<vector<int>> p(n, vector<int>(11));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 10; ++j){
      cin >> f[i][j];
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 11; ++j){
      cin >> p[i][j];
    }
  }
  long long profit = -INF;
  long long temp;
  int cnt;
  for(int bit = 1; bit < (1 << 10); ++bit){
    temp = 0;
    for(int i = 0; i < n; ++i){
      cnt = 0;
      for(int j = 0; j < 10; ++j){
        if(f[i][j] && bit & (1 << j)) cnt++;
      }
      temp += p[i][cnt];
    }
    profit = max(profit, temp);
  }
  cout << profit << endl;
}