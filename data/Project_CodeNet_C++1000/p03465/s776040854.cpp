#include<bitset>
#include<cstdio>
#include<algorithm>

int a[3000];
std::bitset<4000000> dp;

int main(void) {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    if(n==1) {
        printf("%d\n", a[0]);
        return 0;
    }

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        dp |= dp << a[i];
    }

    int r = 0;
    for(int i=0; 2*i<=sum; i++)
        if(dp[i]) r = sum-i;

    printf("%d\n", r);
}
