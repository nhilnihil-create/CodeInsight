#include <bits/stdc++.h>
using namespace std;

int ryuka(int64_t x, vector<int64_t> &vec){
  if (x == 0 || x == 1){
    return vec.at(x);
  }
  else {
    for (int i = 2; i < x+1; i++){
      vec.at(i) = (int64_t)vec.at(i-1) + (int64_t)vec.at(i-2);
    }
    return vec.at(x);
  }
}

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> vec(n+1);
  vec.at(0) = 2LL;
  vec.at(1) = 1LL;
  ryuka(n, vec);
  cout << vec.at(n) << endl;
}