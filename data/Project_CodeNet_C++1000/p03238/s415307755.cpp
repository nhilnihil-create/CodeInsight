#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1) printf("Hello World\n");
    if(n == 2) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d\n", a + b);
    }
    return 0;
}