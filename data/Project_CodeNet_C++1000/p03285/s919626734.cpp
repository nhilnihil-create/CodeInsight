#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;

  bool ans = false;
  rep(i,25){
    rep(j,15){
      if ((n - 4*i - 7*j) == 0){
        ans = true;
      }
    }
  }

  if (ans == true){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}