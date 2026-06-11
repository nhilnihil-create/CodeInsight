#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    ll sum = a + b;
    ll ans = 0;
    if(c - sum <= 1) {
        ans += (b+c);
    } else {
        ans += (sum+1+b);
    }
    printf("%lld\n",ans);
    return 0;
}