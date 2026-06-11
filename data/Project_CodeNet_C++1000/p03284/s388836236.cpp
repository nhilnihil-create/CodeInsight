#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int m;
 
   cin >> n >> m;
  
   int num = n%m;
  
   if(num==0){
     cout << 0 << endl;
   }else{
     cout << 1 << endl;
   }
  
   //cout << n << endl;
   // cout << m << endl;
  
   
  return 0;
}