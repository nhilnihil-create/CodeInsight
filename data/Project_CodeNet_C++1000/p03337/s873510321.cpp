#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	
    int a,b ;    
    cin >> a >> b;
   int ans ;
   if(a+b>a-b){
     if(a+b>a*b){
       ans =a+b ;
     }else{
       ans =a*b ;
     }
   }else{
     if(a-b>a*b){
       ans = a-b ;
     }else{
       ans = a*b ;
     }
   }
  
    cout << ans << endl ;
	return 0;
}
