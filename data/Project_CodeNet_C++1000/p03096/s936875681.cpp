#include<iostream>
#define M std::cin>>
int s[200000],n,c,l,z,x,i,h=1e9+7;main(){M n>>z;c=l=s[z]=1;for(i=1;i<n;i++){M x;if(x!=z)c=(c+s[x])%h,s[x]=(s[x]+l)%h;l=c,z=x;}std::cout<<c;}