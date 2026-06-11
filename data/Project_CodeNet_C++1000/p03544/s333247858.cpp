#include <bits/stdc++.h>
using namespace std;

int64_t ryuka(int x){
  if(x == 0){
    return 2;
  }
  else if(x == 1){
    return 1;
  }else{
    vector<int64_t> L (10000);
    L.at(0) = 2;
    L.at(1) = 1;
    for(int i = 2; i <= x; i++){
      L.at(i) = L.at(i - 2) + L.at(i - 1);
    }
    return L.at(x);
  }
}

int main() {
  int N;
  cin >> N;
  cout << ryuka(N) << endl;
}