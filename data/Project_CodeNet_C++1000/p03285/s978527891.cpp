#include <bits/stdc++.h>
using namespace std;
#define rep(i, n); for (int i = 0; i <= (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n;
  cin >> n;
  rep(i,n/4){
    rep(j,n/7){
      if(i*4+j*7==n){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
