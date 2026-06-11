#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  vector<vector<char>> c(3, vector<char>(3));
  rep(i, 3){
    rep(j, 3){
      cin >> c[i][j];
    }
  }
  cout << c[0][0] << c[1][1] << c[2][2] << endl;

}