#include <iostream>
#include <vector>
 
int main(){
  unsigned n; std::cin >> n;
  unsigned a[n];
  unsigned total=0;
  
  for(int i=0; i<n; i++){
    unsigned tmp;
    std::cin >> tmp;
    a[i] = tmp;
    total += tmp;
  }
  
  float avg = (float)total/n;
  unsigned pos=0;
  float diff = (a[pos]>avg)? a[pos]-avg : avg- a[pos];
  for(int i=1; i<n;i++){
    float tmp = (a[i]>avg)? a[i]-avg : avg- a[i];
    if(tmp<diff){
      diff = tmp;
      pos = i;
    }
  }
  std::cout << pos << std::endl;
  return 0;
}