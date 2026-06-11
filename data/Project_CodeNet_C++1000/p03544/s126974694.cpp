#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> c(N+1);
  for(int i = 0; i < N+1; i++){
    if(i == 0){
      c.at(0) = 2;
    }else if(i == 1){
      c.at(1) = 1;
    }else{
      c.at(i) = c.at(i - 1) + c.at(i - 2);
    }
  }
  cout << c.at(N) << endl;
}
