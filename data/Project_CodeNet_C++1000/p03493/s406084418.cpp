#include <bits/stdc++.h>
using namespace std;

int main(){
  string numbers;
  cin >> numbers;

  int sum = 0;

  for(int i = 0; i < 3; i++){
    if(numbers.at(i) == '1'){
      sum++;
    }
  }

  cout << sum << endl; 
}
