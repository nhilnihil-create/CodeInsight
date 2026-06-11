#include<bits/stdc++.h>
int a[2001],s,n,i;
std::bitset<4000001> d;     
int main(){
    std::cin>>n;d[0]=1;
    for(;i<n;i++)std::cin>>a[i],s+=a[i],d|=(d<<a[i]);
    while(!d[++s/2]){} std::cout<<s/2;
}