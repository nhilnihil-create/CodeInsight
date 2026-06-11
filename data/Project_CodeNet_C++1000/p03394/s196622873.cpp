typedef  long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    
    if(n<=8){
        if(n==3){
            std::cout << "2 5 63" << std::endl;
        }else{
            std::cout << "2 3 4 9 ";
            for (int i = 0; i < n-4; i++) {
                std::cout << 12*i+12<<" ";
            }
            std::cout << std::endl;
        }
        return 0;
    }

    for (int i = 0; i < n/8; i++) {
        std::cout << i*12+2<<" "<<i*12+3<<" "<<i*12+4<<" " <<i*12+6 << " ";
        std::cout << i*12+8<<" "<<i*12+9<<" "<<i*12+10<<" "<<i*12+12 << " ";
    }
    ll offset = n/8;
    
    if(n%8==0){
        std::cout << std::endl;
        return 0;
    }
    if(n%2==1){
        std::cout << offset*12+12<<" ";
    }
    for (int i = 0; i < (n%8)/2; i++) {
        std::cout << offset*12+2+i <<" "<< offset*12+10-i <<" ";
    }
    std::cout << std::endl;
}
