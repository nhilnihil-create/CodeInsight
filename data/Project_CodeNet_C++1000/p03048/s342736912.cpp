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
    int R,G,B,N; std::cin >> R >> G >> B >> N;

    int ans = 0;
    for(int r=0; r<=N/R; r++){
        for(int g=0; g<=N/G; g++){
            int t = r*R + g*G;
            if( 0<=t && t<=N && (N-t)%B==0 ) ans++;
        }
    }

    std::cout << ans << "\n";
    return 0;
}