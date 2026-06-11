#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
    ll n;
    scanf("%lld", &n);
    if (n%2==0) {
        printf("%lld\n", n);
    }
    else{
        printf("%lld\n", n*2);
    }
    return 0;
}