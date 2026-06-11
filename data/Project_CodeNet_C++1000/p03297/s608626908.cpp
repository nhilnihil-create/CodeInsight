#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    while(b){
        ll t = a / b;
        a -= b * t;
        swap(a, b);
    }
    return a;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        if (a < b || d < b) printf("No\n");
        else if (c >= b - 1) printf("Yes\n");
        else{
            ll g = gcd(b, d);
            ll k = (a - (c + 1 - b)) / g;
            if (a - k * g >= 0) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}