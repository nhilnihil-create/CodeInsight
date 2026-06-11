#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    for(int i = a; i <= min(b, a + k - 1); i++) printf("%d\n", i);
    for(int i = max(a + k, b - k + 1 ); i <= b; i++) printf("%d\n", i);
    return 0;
}