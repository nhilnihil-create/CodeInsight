#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;


int main(){

  int N;
  
  cin >> N;
  
  int sum=0;
  for(int i=1; i<=N; i++){
    int cnt =0;
  	for(int j=1; j<=i; j++){
    	if(i%j==0)
          cnt++;
    }
    if(i%2!=0 && cnt==8)
      sum++;
  }
 
  cout << sum << endl;
  

  
  return 0;
  
}
