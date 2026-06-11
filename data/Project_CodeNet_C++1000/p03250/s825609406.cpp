#include<iostream>
int main(){int a,b,c;std::cin>>a>>b>>c;int ans=a+b+c+9*(std::max(a,std::max(b,c)));std::cout<<ans<<std::endl;return 0;}