#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int64_t> x(87);
  x.at(0) = 2;
  x.at(1) = 1;
  int N;
  cin >> N;
  for(int i = 2; i < N+1; i++){
    x.at(i) = x.at(i-2) + x.at(i-1);
  }
  cout << x.at(N);
}
  