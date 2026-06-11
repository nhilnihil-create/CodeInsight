#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n,s,g;
  std::cin >> n;
  std::vector<int> l(n);
  for(int i=0;i<n;i++){
    std::cin >> l[i];
  }

  std::sort(l.begin(),l.end());
  
  s=l.size()-1;
  for(int c=0;c<s;c++){
    g=g+l[c];
  }
  s=l.back();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ;
  if(g>s){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }
  return 0;
}