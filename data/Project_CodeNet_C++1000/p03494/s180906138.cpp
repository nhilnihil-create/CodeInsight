#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  bool is_divided = true;
  for(int i = 0;i < N;i++)cin >> A[i];
  int cnt = 0;
  while(is_divided){
    for(int i = 0;i < N;i++){
      if(A[i] % 2 == 0){
        A[i] /= 2;
      }else{
        is_divided = false;
      }
    }
    if(is_divided){
      cnt++;
    }
  }
  cout << cnt << endl;
}