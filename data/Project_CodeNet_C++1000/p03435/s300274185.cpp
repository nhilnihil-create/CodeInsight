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
    std::vector<std::vector<int>> c(3,std::vector<int>(3,0));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cin >> c[i][j];
        }
    }

    std::vector<int> a(3,0), b(3,0);
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    a[0] = 0;
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    bool flag = true;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if( c[i][j]!=a[i]+b[j] ) flag=false;
        }
    }

    if(flag){
        std::cout << "Yes" << "\n";
    }else{
        std::cout << "No" << "\n";
    }
    return 0;
}