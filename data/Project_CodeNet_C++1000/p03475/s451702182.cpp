#include <iostream>
int main(){
  int n, c[501], s[501], f[501], a[501]={}, i=0,j, t;
  std::cin>>n;
  while(std::cin>>c[i]>>s[i]>>f[i])i++;
  for(i=0;i<n-1;++i){
    t=0;
    j=i;
    while(j<n-1){
      if(t>=s[j]&&t%f[j]==0){t+=c[j];++j;}
      else ++t;
    }
    a[i] = t;
  }
  for(i=0;i<n;++i)std::cout<<a[i]<<"\n";
}
