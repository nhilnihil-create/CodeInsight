#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    if ( d == 0 ) {
        printf("%.8f\n", (double)(m-1)/(double)n);
        return 0;
    }
    printf("%.8f", 2 * ( (double)n - (double)d ) / ( (double)n * (double)n ) * (double)(m - 1) );
    return 0;
}
