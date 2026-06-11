#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int i=0;
  string A;
  cin >> N;
  
 while(i<N){
     cin >> A;
     if(A=="Y"){
         cout<<"Four";
         break;
     }
     
     i++;
     if(i==N-1){
       cout<<"Three";  
     }
 }
 
}