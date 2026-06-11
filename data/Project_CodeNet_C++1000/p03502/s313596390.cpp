#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin >> N;
int Nc = N;
int sum = 0;
  for(int i = 0; i < 9; i++){
    sum += N % 10;
    N = N / 10;
  }
  if(Nc % sum == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
