#include<iostream>
int c[200000],a[200000],n,d=1,r,x,i;main(){std::cin>>n;for(;n--;)std::cin>>a[r++];for(i=0;i<r;++i){x=a[i];if(x!=a[i-1])c[x]=(c[x]+d)%int(1e9+7);d=c[x];}std::cout<<d;}
