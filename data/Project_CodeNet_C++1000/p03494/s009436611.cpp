#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i, N){
  cin >> vec.at(i);
  }
  rep(j, 30){
    rep(i, N){
      if(vec.at(i) % 2 == 1){
      	cout << j << endl;
      	return 0;
      }
      vec.at(i) /= 2;
    }
  }
  cout << 30 <<endl;
  return 0;
}