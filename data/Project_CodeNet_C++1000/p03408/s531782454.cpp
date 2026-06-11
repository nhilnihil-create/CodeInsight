#include <bits/stdc++.h>
using namespace std;
 
int main() {
   int N,num=1,num2=0;
   cin >> N;
   vector<string> Blue(N);
    for (int i = 0; i < N; i++) {
      cin >> Blue.at(i);
    }

   int M;
   cin >> M;
   vector<string> Red(M);
    for (int ii = 0; ii < M; ii++) {
     cin >> Red.at(ii);
     }
    
   for (int j = 0; j < N ;j++){
     for (int jj = 1;jj < (N);jj++ ){
      if (Blue.at(j)==Blue.at (jj)){
       num ++; 
      }
     }
     for (int k = 0;k < (M);k++ ){
      if (Blue.at(j)==Red.at(k)){
        num -- ;  
     	 }
 	   }
     if (num2 < num ){
      num2 = num;
    	} 
     num =0;
    }
  	if (num2<0){
  	num2 =0;
  				}
       cout << num2<< endl;
   }