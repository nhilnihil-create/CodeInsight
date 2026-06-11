#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int n,maxv = 0;
  cin >> n;
  vector<int> v(n),c(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < n; i++){
    cin >> c[i];
    if (v[i] - c[i] > 0){
      maxv += v[i] - c[i];
    }
  }
  cout << maxv << '\n';
  return 0;
}