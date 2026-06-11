typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    
    ll sum = 0;
    ll minb=1e10;
    for (int i = 0; i < n; i++) {
        ll a,b;
        std::cin >> a>>b;
        sum += a;
        if(a-b>0){
            minb=min(minb,b);
        }
    }
    if(minb==1e10){
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << sum-minb << std::endl;
}
