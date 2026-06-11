#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  int tmp = N;
  int sum = 0;
 
  while(N > 0){
    sum +=  N % 10;
    N /= 10;
     
  }
  
   for(int i = 1 ;i <= 5 ; i++){
    int x = pow(10,i);
    if(x==tmp) sum = 10;
   }
  
 cout << sum << endl;
  
}