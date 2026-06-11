typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,y;
    std::cin >> n>>y;
    y /= 1000;
    
    for (int i = 0; i <= n; i++) {
        if(i*10>y)continue;
        ll now = y-i*10;
        for (int j = 0; j <= n-i; j++) {
            if(now == j*5+n-i-j){
                std::cout << i<<" "<<j<<" "<<n-i-j << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1<<" "<<-1<<" "<<-1 << std::endl;
}