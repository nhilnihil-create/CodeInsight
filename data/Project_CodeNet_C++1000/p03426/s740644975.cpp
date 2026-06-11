#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h ,w, D;
    cin >> h >> w >> D;

    long long px[90001], py[90001];

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            long long a;
            cin >> a;
            px[a] = j;
            py[a] = i;
        }
    }

    long long d[90001];

    for(long long i = D+1; i <= h*w; i++) d[i] = d[i-D] + abs(px[i] - px[i-D]) + abs(py[i] - py[i-D]);

    long long q;
    cin >> q;

    for(long long i = 0; i < q; i++){
        long long l, r;
        cin >> l >> r;

        printf("%lld\n", d[r]-d[l]);
    }
    return 0;
}