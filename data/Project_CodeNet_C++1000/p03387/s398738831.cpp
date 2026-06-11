#include<bits/stdc++.h>
int main(){
   int a[3];for(int i=0;i<3;i++)std::cin>>a[i];
   std::sort(a,a+3);
   int l=2*a[2]-(a[1]+a[0]);
   std::cout<<(l%2?(l+3)/2:l/2);
}