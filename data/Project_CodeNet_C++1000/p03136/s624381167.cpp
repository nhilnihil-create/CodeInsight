#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> v(n);
  rep(i, n){
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  int maxL = v[n-1];
  rep(i, n-1){
  	sum += v[i];
  }
  if(maxL < sum){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
  return 0;
}