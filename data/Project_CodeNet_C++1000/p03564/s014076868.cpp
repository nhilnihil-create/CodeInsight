#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k, l = 1;
  cin >> n >> k;
  rep(i,n){
    if (l > k)
      l += k;
    else
      l *= 2;
  }
  cout << l << endl;
}