#include<iostream>
#include<algorithm>

int main(){
int n;
   std::cin >> n;
   int a[n];
   for(int i=0;i<n;i++)
       std::cin >> a[i];
  std::sort(a,a+n,std::greater<int>());
  int al=0,b=0;
  for(int i=0;i<n;i++){
    if(i&1)
       b+=a[i];
    else
       al+=a[i];
  }
  std::cout << al-b << std::endl;
 return 0;
}