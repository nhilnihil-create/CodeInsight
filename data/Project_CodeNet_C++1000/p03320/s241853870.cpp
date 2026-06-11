//code by lynmisakura.wish to be accepted!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, ll mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
ll k;

int dig(long long x){
    int ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
double s(long long x){
    return (double)x / (double)dig(x);
}
long long f(long long n){
    if(n <= 8) return n+1;
    int d = (int)log10(n) + 1;
    double MIN = (double)LONG_MAX;
    long long res;
    for(ll i = 0;i <= d;i++){
        if(MIN > s(qp(10,i+1)*(n/qp(10,i+1) + 1)-1)){
            MIN = s(qp(10,i+1)*(n/qp(10,i+1) + 1)-1);
            res = qp(10,i+1)*(n/qp(10,i+1) + 1)-1;
        }
    }
    return res;
}

int main(void){
    cin >> k;
    long long n = 9;
    for(int i = 0;i < k;i++){
        if(i <= 8) n = i+1;
        else n = f(n+1);
        printf("%lld\n",n);
    }
    return 0;
}