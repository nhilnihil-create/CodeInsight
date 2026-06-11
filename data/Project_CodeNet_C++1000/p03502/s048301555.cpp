#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int digitSum = 0;
  int X = N;
  for( int digit=1; digit<=8; digit++ ){
    digitSum += (X % 10);
    X /= 10;
  }
  
  
  if( (N % digitSum) == 0 ){
    cout << "Yes" << endl;
  }
  else{
  	cout << "No" << endl;
  }
}