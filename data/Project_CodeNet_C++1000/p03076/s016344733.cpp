#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
  
   int a[5];
 
   int sum = 0;
   int min = 10;
   for(int i = 0;i<5;i++){
     
     cin >> a[i];
     
      int b = 0;
    if(a[i]%10!=0){
     b = 10-a[i]%10;
     
     }
     
     sum = sum+a[i]+b;
   
     
     if(a[i]%10<min&&a[i]%10!=0){
       
       min=a[i]%10;
       
     }
     
     
   }
  
   min = 10-min;
   
   cout << sum-min << endl;
   
  return 0;
}