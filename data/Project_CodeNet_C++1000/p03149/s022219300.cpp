#include <iostream>
#include <vector>

int main(){
    std::vector<bool> vec(10, true);
    vec.at(1) = false;
    vec.at(9) = false;
    vec.at(7) = false;
    vec.at(4) = false;
    
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    vec.at(a) = true;
    vec.at(b) = true;
    vec.at(c) = true;
    vec.at(d) = true;

    std::string ans = "NO";
    if(std::end(vec) == std::find(std::begin(vec), std::end(vec), false)){
        ans = "YES";
    }

    std::cout << ans << std::endl;

    return 0;
}