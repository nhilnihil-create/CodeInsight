#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b[i];
  vector<vector<int>> v(n,vector<int> (m));
  rep(i,n){
    rep(j,m) cin >> v[i][j];
  }
  int cnt = 0;

  rep(i,n){
    int sum = 0;
    rep(j,m){
      sum += b[j]*v[i][j];
    }
    if (sum  + c > 0) cnt++;
  }
  cout << cnt << endl;
  

  return 0;
}
