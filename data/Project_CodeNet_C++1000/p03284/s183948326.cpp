#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if(n % k == 0) printf("0\n");
    else printf("1\n");
    return 0;
}