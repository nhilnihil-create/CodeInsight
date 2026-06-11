#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  rep(i,n) cin >> v[i];

  int min = 1e5;
  int sum = 0;
  rep(i,n){
    sum += v[i];
    if (v[i] < min) min = v[i];
  }

  cout << n + (x - sum) / min << endl;
  return 0;
}