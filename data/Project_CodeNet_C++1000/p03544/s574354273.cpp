#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
  int N;
  cin >> N;
  ll l_0 = 2;
  ll l_1 = 1;
  ll tmp;
  if (N==1) cout << l_1 << endl;
  else {
    rep(i,N-1){
    tmp = l_0;
    l_0 = l_1;
    l_1 = l_0 + tmp;
  }
  cout << l_1 << endl;
  }
}