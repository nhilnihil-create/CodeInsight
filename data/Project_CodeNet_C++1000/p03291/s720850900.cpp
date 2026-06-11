#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處
char s[100005];
LL a[100005];
LL ab[100005];
LL abc[100005];
const LL m = 1000000007;
int main() {
    scanf("%s", s);
    int len = strlen(s);


    LL n = 1;
    if (s[0] == 'A') {
        a[0] = 1;
    } else if (s[0] == '?') {
        a[0] = 1;
        n = 3;
    }

    for (int i = 1; i < len; i++) {
        switch (s[i]) {
            case 'A':
            a[i] = (a[i-1] + n) % m;
            ab[i] = ab[i-1];
            abc[i] = abc[i-1];
            break;
            case 'B':
            a[i] = a[i-1];
            ab[i] = (ab[i-1] + a[i-1]) % m;
            abc[i] = abc[i-1];
            break;
            case 'C':
            a[i] = a[i-1];
            ab[i] = ab[i-1];
            abc[i] = (abc[i-1] + ab[i-1]) % m;
            break;
            case '?':
            a[i] = (a[i-1]*3 + n) % m;
            ab[i] = (ab[i-1]*3 + a[i-1]) % m;
            abc[i] = (abc[i-1]*3 + ab[i-1]) % m;
            n *= 3;
            n %= m;
            break;
        }
    }
    printf("%lld\n", abc[len-1]);
}
