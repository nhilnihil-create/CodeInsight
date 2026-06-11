#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,realmax=100;
  cin >> N ;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int max = 0;  
     for (int ii = 0; ii < 50; ii++) {    
        if (A % 2 == 0){
      	  A = A / 2;
     	  max++;
        }else{
      		break;
    	}
     } 
   if( max < realmax ){
    realmax = max;  
    }
  }
  cout << realmax << endl;
}
