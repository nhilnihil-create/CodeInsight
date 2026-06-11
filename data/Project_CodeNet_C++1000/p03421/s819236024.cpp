#include <iostream>
using namespace std;
typedef long long LL;
LL n, a, b, cnt[300000+10];

int main() {
    cin >> n >> a >> b;
    int rem = n - a;
    int typ = a;

    if (b-1 > rem || (b-1)*a < rem) {
        return !printf("-1\n");
    }

    rem -= (b-1);
    cnt[a] = (b-1); 
    for (int i = 1; i <= a-1; i++) {
        if (rem >= b-1) {
            rem -= b-1;
            cnt[i] = b-1;
        } else {
            cnt[i] = rem;
            rem = 0;
        }
    }
    for (int i = 1; i <= a; i ++) cnt[i] ++;
    for (int i = 1; i <= a; i ++) {
        cnt[i] += cnt[i-1];
    }

    for (int i = 1; i <= a; i ++) {
        for (int j = cnt[i]; j > cnt[i-1]; j --) {
            printf("%d ", j);
        }
    }
    printf("\n");
}