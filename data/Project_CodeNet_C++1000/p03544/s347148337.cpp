#include<bits/stdc++.h>
using namespace std;

int64_t lucas(int n){
  if(n == 0){
    return 2;
  }
  if(n == 1){
    return 1;
  }
  int64_t sum = 0;
  int64_t tmp1 = 2;
  int64_t tmp2 = 1;
  for(int i = 2;i <=n;i++){
    sum = tmp1 + tmp2;
    tmp1 =tmp2;
    tmp2 = sum;
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  cout << lucas(n) << endl;
}
