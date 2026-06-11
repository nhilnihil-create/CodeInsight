#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A,c, d;
  cin >> N;
   for (int i = 0;i<N ;i++){
     cin >> A;
       c = 0;
     for (int b = 2; true ;b *= 2){
     if(A%b == 0){
       c++;
     			} 
       else{
       break;
       }
     }
     if (i == 0 || d > c){
       d = c;
     }
   }									
  cout << d << endl;
			}