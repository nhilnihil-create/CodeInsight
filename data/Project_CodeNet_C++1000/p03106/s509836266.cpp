#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;


int main(){

  int A,B,K;
  
  cin >> A >> B >> K;
  vector<int>n(110);
  
  int C = min(A, B);
  for(int i=1; i<=C; i++){
  	if(A%i==0 && B%i==0)
      n.at(i) =i;
  }
  
  sort(n.begin(), n.end(), greater<int>());
  
  cout << n.at(K-1) << endl;

  
  return 0;
  
}
