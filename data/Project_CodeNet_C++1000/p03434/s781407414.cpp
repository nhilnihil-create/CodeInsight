#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> number(N);
  
  for(int i = 0; i < N; i++){
    cin >> number.at(i);
  }

  sort(number.begin(), number.end());
  reverse(number.begin(), number.end());

  int Alice = 0;
  int Bob = 0;
  
  for(int i = 0; i < N; i += 2){
    Alice += number.at(i);
  }

  for(int i = 1; i < N; i += 2){
    Bob += number.at(i);
  }

  cout << Alice - Bob << endl;
}