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
   int n,m,l;
 
   cin >> n >> m >> l;
  
   int a[n];
  
  for(int i = 0;i<n;i++){
     
    cin >> a[i];

   }
  
  int ans = 0;
  
  for(int i = 0;i<n;i++){
     
    int sum = 0;
    
    for(int k = 0;k<100000;k++){
      
      
      if(1 + k*a[i]>=m+1){
        break;
      }
      //cout << 1 + k*a[i];
      
      sum = sum + 1;
    }
    
    ans = ans + sum;
    
   }
  
   cout << ans + l << endl;
   
  return 0;
}