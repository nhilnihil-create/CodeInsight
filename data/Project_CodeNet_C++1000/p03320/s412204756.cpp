#include<bits/stdc++.h>
using namespace std;

typedef double lf;
typedef long long ll;

ll sum(ll val) {
    ll ret = 0;
    while(val) ret += val % 10, val /= 10;
    return ret;
}

int K;

int main() {
    cin >> K;

    ll cur = 1;
    ll p = 1;
    lf mx = 0;
    while(K) {
        ll s = sum(cur);
        ll r = (cur + s - 1) / s;
        if(r > p) {
            while(r > p) p *= 10;
            cur = (cur + p) / p * p - 1;
        }

        printf("%lld\n", cur);
        K--;
        cur += p;
    }
}
