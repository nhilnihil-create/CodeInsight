#include <iostream>
using namespace std;
using ll = long long;

const ll M = 1e9 + 7;
ll n, a[200005], b[200005], d[200005], s[200005];

int main() {
    scanf("%lld", &n);
    s[0] = d[0] = 1;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if(b[a[i]] > 0 && b[a[i]] < i - 1) {
            d[i] = s[b[a[i]]];
        }
        s[i] = s[i - 1] + d[i];
        s[i] %= M;
        b[a[i]] = i;
    }
    cout<<s[n]<<endl;
    return 0;
}