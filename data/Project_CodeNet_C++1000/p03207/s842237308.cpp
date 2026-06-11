#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n){
  	cin >> v.at(i);
  }
  int hight_price = *max_element(v.begin(), v.end());
  int sum = 0, cnt = 0;
  rep(i, n){
    if(v[i] == hight_price && cnt == 0){
    	v[i] /= 2;
      	cnt++;
    }
    sum += v[i];
  }
  cout << sum << endl;
  return 0;
}