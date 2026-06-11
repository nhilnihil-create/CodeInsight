#include <bits/stdc++.h>

using namespace std;

int n;
int a[200000], b[200000];

bool allSame() {
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

int main() {
    scanf("%d", &n);

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", a+i, b+i);
        sum += a[i];
    }

    if(allSame()) {
        printf("0\n");
        return 0;
    }

    long long small = 1e9+7;
    for(int i = 0; i < n; i++)
        if(a[i] > b[i] && b[i] < small)
            small = b[i];

    printf("%lld\n", sum - small);
    return 0;
}