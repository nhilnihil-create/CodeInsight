typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() { 
    ll t;
    std::cin >> t;
    for (int ii = 0; ii < t; ii++) {
        ll a,b,c,d;
        std::cin >> a>>b>>c>>d;
        
        if(a<b){
            std::cout << "No" << std::endl;
            continue;
        }
        
        if(b>d){
            std::cout << "No" << std::endl;
            continue;
        }
        
        if(b<=c){
            std::cout << "Yes" << std::endl;
            continue;
        }
        if( b-gcd(b,d)+a%gcd(b,d) >c%b ){
            std::cout << "No" << std::endl;
        }else{
            std::cout << "Yes" << std::endl;
        }
    }
}