#include<bits/stdc++.h>
using namespace std;
int main(){
  int A=0, B=0, C=0, X=0, sum=0, count=0;
  cin >> A >> B >> C >> X;
 for(int i=0;i<=A;i++){
   sum = X-(500*i);
     if(sum == 0){
       count++;
     }
   for(int j=0;j<=B;j++){
     sum = X-(500*i)-(100*j);
     if(sum == 0 && j != 0){
         count++;
       }
     for(int k=0;k<=C;k++){
       sum = X-(500*i)-(100*j)-(50*k);
       if(sum == 0 && k != 0){
         count++;
       }
     }//for k
   }//for j
 }//for i
  cout << count << endl;
}