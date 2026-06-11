#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int A, B;
  cin >> A >> B;

  int counter = 0;

  for(int i = A; i <= B; i++){
    
    vector<int> N(5);
    int n = i;
    
    for(int j = 0; j < 5; j++){
      N.at(4 - j) = n % 10; 
      n /= 10;
    }
    
    if(N.at(0) == N.at(4) && N.at(1) == N.at(3)){
      counter++;
    }
  }
  
  cout << counter << endl;
  
}