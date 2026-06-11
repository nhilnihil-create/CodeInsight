
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main () {
  int n;
  cin >> n;
  vector<tuple<string,int,int>> a(n);
  for (int i = 0; i < n; i++){
    cin >> get<0>(a[i]) >> get<1>(a[i]);
    get<2>(a[i]) = i+1;
    get<1>(a[i]) *= -1;
  } 
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++){
    cout << get<2>(a[i]) << '\n';
  }
  return 0;
}