#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(c.begin(), c.end(), greater<int>());
  int a = 0, b = 0;
  rep(i, n){
    if(i % 2 == 0){
      a += c[i];
    }else{
      b += c[i];
    }
  }
  cout << a - b << endl;
}
