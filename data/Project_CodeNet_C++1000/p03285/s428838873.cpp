#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i <= (int)(n); i++)

int main() {
  int N;
  cin >> N;
  bool you = false;
  
  rep(i, N / 7) {
    rep(j, N/ 4) {
      if(i * 7 + j * 4 == N) {
        you = true;
        break;
      }
    }
    if(you) break;
  }
  
  if(you) cout << "Yes" << endl;
  else cout << "No" << endl;
}