#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){

  int N, T, A, H;
  cin >> N >>T >> A;
  int ans = 0;

  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> H;
    vec.at(i) = H;
  }

  double tmp;
  double diff = 100000000;
  for (int i = 0; i < N; i++) {
    tmp = T - vec.at(i)*0.006;
    if((tmp - A)*(tmp - A) < diff){
      diff = (tmp - A)*(tmp - A);
      ans = i+1;
    }
  }

  cout << ans << endl;

  return 0;
}