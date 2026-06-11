#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

int main(){
  
  long long int n, m, d;
  
  scanf("%lld%lld%lld", &n, &m, &d);
  
  std::cerr << "Answer:" << std::endl;
  if(d == 0){
    std::cout << std::setprecision(14) /*<< std::scientific */<< (m-1.0)/n << std::endl;
  }
  else{ // if(d>0)
    std::cout << std::setprecision(14) /*<< std::scientific*/ << (2.0*(n-d))/(n*n) * (m-1.0) << std::endl;
  }
  
  return 0;
  
}
