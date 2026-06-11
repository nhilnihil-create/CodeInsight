#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    std::string s; std::cin >> s;
    std::string keyence = "keyence";
    for(int i=0; i<keyence.size()+1; i++){
        if(s.substr(0,i)+s.substr(s.size()-(keyence.size()-i))==keyence){
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}
