#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
  
  long long int a,b,c,d[110],e,f,g;
  
  
  cin >>a;
   cin >>b>>c ;
  for(int i=0;i<a;i++)
  cin >> d[i];
  e =0,f=0,g=0;
 for(int i=0;i<a;i++){
   if(d[i]<=b){
     e++;
   }
   if(d[i]>=b+1 &&d[i]<=c){
     f++;
   }
   if(d[i]>c){
     g++;
   }
 }
cout << min( min(e,f),g) << endl;
 
  return 0;
}
 
