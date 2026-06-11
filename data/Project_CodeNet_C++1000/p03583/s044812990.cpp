#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;

    cin >> N;

    for(ll h = 1; h <= 3500; h++ ){
    for(ll n = 1; n <= 3500; n++ ){
        ll denom_w = 4*h*n - N*n - N*h;
        ll numer_w = N*h*n;
        if( denom_w <= 0 ){
            continue;
        }
        if( numer_w % denom_w != 0 ){
            continue;
        }

        //DEBUG("numer=%lld denom=%lld", numer_w, denom_w);

        cout << h << " " << n << " " << (numer_w/denom_w) << endl;
        return 0;
    }
    }
}
