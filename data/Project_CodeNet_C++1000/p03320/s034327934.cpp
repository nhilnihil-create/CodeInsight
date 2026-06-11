#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std ;

int n ;
long long ans ;
long long base = 1ll ;

double s(long long x){
    int ret = 0 ; long long y = x ;
    while (x) ret += (x % 10ll), x /= 10ll ;
    return (1.0 * y) / (1.0 * ret) ;
}
int main(){
    cin >> n ;
    while (n --){
        while (1){
            if (s(ans + base) > s(ans + base * 10ll))
                base *= 10ll ; else break ;
        }
        ans += base ;
        printf("%lld\n", ans) ;
    }
}
