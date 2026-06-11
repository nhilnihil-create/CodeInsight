#include<iostream>
#include<vector>
#include<string>
#include<list>

int main(){
    int n;
    std::cin >> n;
    if(n == 0){
        std::cout << 0 << std::endl;
        return 0;
    }
    
    std::list<int> ans;
    while(std::abs(n) > 0){
        ans.push_front(std::abs(n % 2));
        n = (n - std::abs(n % 2)) / (-2);
    }
    
    for(auto a : ans) std::cout << a;
    std::cout << "\n" << std::endl;

    return 0;
}
