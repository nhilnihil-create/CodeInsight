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
    ll H, W; std::cin >> H >> W;
    std::string temp(W+2,'.');
    std::vector<std::string> s(H+2, temp);

    for(int i=0; i<H; i++){
        std::string b; std::cin >> b;
        for(int j=0; j<W; j++){
            s[i+1][j+1] = b[j];
        }
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(s[i][j]=='#'){
                if(s[i][j+1]=='#'){
                    ;
                }else if(s[i][j-1]=='#'){
                    ;
                }else if(s[i+1][j]=='#'){
                    ;
                }else if(s[i-1][j]=='#'){
                    ;
                }else{
                    std::cout << "No";
                    return 0;
                }
            }
        }
    }

    std::cout << "Yes";
    return 0;
}
