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
    int a,b,c,x; std::cin>>a>>b>>c>>x;

    int ans=0;
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            for(int k=0; k<=c; k++){
                if(500*i+100*j+50*k==x) ans++;
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
