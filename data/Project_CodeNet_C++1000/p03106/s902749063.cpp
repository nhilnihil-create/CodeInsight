
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
  int a,b,k,cnt = 0;
  vector<int> n;
  cin >> a >> b >> k;
  for (int i = 1; i <= 100; i++){
    if (a % i == 0 && b % i == 0){
      n.push_back(i);
      cnt++;
    }
  }
  reverse(n.begin(), n.end());
  cout << n[k-1] << '\n';
  return 0;
}