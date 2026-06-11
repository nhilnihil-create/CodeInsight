#include<bits/stdc++.h>
using namespace std;

int main (){
 int N,M,X;
 cin >> N>>M>>X;
 int u=0,d=0;
  
 for(int i=0;i<M;i++){
   int a;
   cin >> a;
   if (a>X){
     u++;
   }
   else{
     d++;
   }
 }
  
 if(u>d){
   cout << d << endl;
 }
  else{
    cout << u << endl;
  }
  
}