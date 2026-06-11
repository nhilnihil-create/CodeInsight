#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    if(2*k-1 <= n) puts("YES");
    else puts("NO");
    return 0;
}
