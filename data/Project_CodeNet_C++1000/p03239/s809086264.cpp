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
  int n,t,m = 10000;
  cin >> n >> t;
  vector<int> c(n),u(n);
  for (int i = 0; i < n; i++){
    cin >> c[i] >> u[i];
    if (u[i] <= t && c[i] < m){
      m = c[i];
    }
  }
  if (m != 10000){
    cout << m << '\n';
  }
  else{
    cout << "TLE\n";
  }
  return 0;
}