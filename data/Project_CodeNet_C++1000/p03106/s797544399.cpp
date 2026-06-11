#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

typedef int LL;
using namespace std;

int main() {
    LL A, B, K, cnt = 0;
    scanf("%d%d%d", &A, &B, &K);
    for (LL i = A; i >= 1; i--) {
        if (A % i == 0 && B % i == 0)
            cnt += 1;
        if (cnt == K) {
            printf("%d\n", i);
            return 0;
        }
    }
}