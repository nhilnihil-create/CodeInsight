#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(10));
  rep(i, n){
    rep(j, 10){
      cin >> vec[i][j];
    }
  }
  vector<vector<int>> point(n, vector<int>(11));
  rep(i, n){
    rep(j, 11){
      cin >> point[i][j];
    }
  }
  int biggest = mod;
  for (int bit = 0; bit < (1<<10); ++bit) {
    vector<int> S;
    for (int i = 0; i < 10; ++i) {
      if (bit & (1<<i)) {
        S.push_back(i);
      }
    }
    if(S.empty()) continue;
    int sum = 0;
    rep(i, n){
      int cnt = 0;
      for(auto p : S){
        if(vec[i][p] == 1) cnt++; 
      }
      sum += point[i][cnt];
    }
    if(biggest == mod) biggest = sum;
    else biggest = max(biggest, sum);
  }
  cout << biggest << endl;
  return 0;
}