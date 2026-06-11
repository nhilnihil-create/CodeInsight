#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, T;
    cin >> n >> T;

    long long minv = 1e9;
    for(long long i = 0; i < n; i++){
        long long c, t;
        cin >> c >> t;
        if(t <= T) minv = min(minv, c);
    }

    if(minv == 1e9) printf("TLE\n");
    else printf("%lld\n", minv);

    return 0;
}