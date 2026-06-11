#include <iostream>

int main(){
    int n,k;
    std::cin>>n>>k;
    int x =(n%2? n/2+1:n/2);
    std::cout<<(x<k?"NO":"YES");
}