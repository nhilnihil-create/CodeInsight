#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> fav(n, vector<bool>(m, false));
  rep(i, n){
    int k; cin >> k;
    rep(j, k){
      int a; cin >> a; a--;
      fav[i][a] = true;
    }
  }
  
  int count = 0;
  rep(i, m){
    bool flag = true;
    rep(j, n){
      if (!fav[j][i]){
        flag = false;
        break;
      }
    }
    if (flag) count++;
  }
  cout << count << endl;
  
  return 0;
}