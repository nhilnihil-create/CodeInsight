#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }

    return gcd(y, x%y);
}
int main(){
    long long n, x;

    cin >> n >> x;

    long long g = 0;

    long long xx[n];

    for(long long i = 0; i < n; i++){
        cin >> xx[i];
    }

    for(long long i = 0; i < n; i++){
        g = gcd(abs(xx[i] - x),g);
    }

    printf("%lld\n", g);

    return 0;

}