#include<iostream>
#include<algorithm>
 
int main(){
 
    size_t n, m;
    std::cin >> n >> m;
    auto p = std::minmax(n, m);
 
    if(p.first == 1){
        if(p.second == 1){
            std::cout << 1 << std::endl;
        }else{
            std::cout << p.second - 2 << std::endl;
        }
    }else{
        std::cout << (p.first - 2) * (p.second - 2) << std::endl; 
    }
 
    return 0;
}