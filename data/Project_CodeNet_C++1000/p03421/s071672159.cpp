#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b;

int main() {
    scanf("%lld%lld%lld",&n,&a,&b);
    if (a*b<n||a+b>n+1) {
        printf("-1\n");
        return 0;
    }
    if (a==1) {
        for (int i=n;i;i--) printf("%d ",i);
        printf("\n"); return 0;
    }
    ll m = (n-1-b)/(a-1);
    ll p = (n+1-b)-(a-1)*m;
    for (int i=0;i<m;i++) {
        for (int j=n+1-i*a-a;j<=n-i*a;j++) printf("%d ",j);
    }
    for (int j=n+1-m*a-p;j<=n-m*a;j++) printf("%d ",j);
    for (int j=n-m*a-p;j;j--) printf("%d ",j);
    printf("\n");

    return 0;
}
