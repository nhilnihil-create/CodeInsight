#include <iostream>
int main(){long long k,a,b;std::cin>>k>>a>>b;std::cout<<(!(a<b-1)?k+1:((k-a+1)/2)*(b-a)+a+(k-a+1)%2);}
