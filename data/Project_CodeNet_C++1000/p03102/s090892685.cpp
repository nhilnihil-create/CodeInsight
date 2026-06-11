#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> vec_B(M); 
  rep(i, M) {
    cin >> vec_B.at(i);
  }
  vector<vector<int>> vec(N, vector<int>(M));
  rep(i, N) {
    rep(j, M) {
      cin >> vec.at(i).at(j);
    }
  }
  int c = 0;
  int AA = 0;
  rep(i, N) {
    rep(j, M) {
      AA += vec.at(i).at(j) * vec_B.at(j);
    }
    if(AA + C > 0) {
      c++;
    }
    AA = 0;
  }
  cout << c << endl;
}