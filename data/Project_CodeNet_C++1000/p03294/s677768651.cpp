#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,sum = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    int number;
    cin >> number;
    number--;
    sum +=number;
  }
  cout << sum << endl;
}