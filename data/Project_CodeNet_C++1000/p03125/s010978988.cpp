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
    int n;
    int m;
 
   cin >> n >> m;
  
  if(m%n==0){
    cout << n+m << endl;
  }else{
     cout << m-n << endl;
  }
  
  
  
  return 0;
}