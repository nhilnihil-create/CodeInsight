#include<iostream>
#define M std::cin>>
int s[200001];main(){int n,c,l,z,x,h=1e9+7;M n;M z;c=l=s[z]=1;for(int i=2;i<=n;i++){M x;if(x!=z){c+=s[x];c%=h;s[x]+=l;s[x]%=h;}l=c;z=x;}std::cout<<c;}