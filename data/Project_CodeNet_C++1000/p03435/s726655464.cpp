#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  vector<int> vec(9);
  rep(i, 9){
    cin >> vec.at(i);
  }
  bool check = false;
  rep(a1, 101){
    rep(a2, 101){
      rep(a3, 101){
        rep(j, 3){
          int b = vec.at(j) - a1;
          int bb = vec.at(3 + j) - a2;
          int bbb = vec.at(6 + j) - a3;
          if(b != bb || bb != bbb || b != bbb)
            break;
          if(j == 2)
            check = true;
        }
      }
    }
  }
  if(check)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}