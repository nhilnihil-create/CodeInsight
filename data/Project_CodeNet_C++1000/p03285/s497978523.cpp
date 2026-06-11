#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(void){
  int n;
  cin >> n;
  
  rep(i,n) {
      rep(j,n) {
          if (i*4 + j*7 == n) {
              cout << "Yes" << endl;
              return 0;
          }
      }
  }
  
  cout << "No" << endl;
}
