#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int a, b; std::cin >> a >> b;
    std::string s; std::cin >> s;

    bool flag=true;
    for(int i=0; i<s.size(); i++){
        if(i==a){
            if(s[i]!='-') flag=false;
        }else{
            if(s[i]=='-') flag=false;
        }
    }

    std::cout << ((flag==true)?("Yes"):("No")) << "\n";
    return 0;
}
