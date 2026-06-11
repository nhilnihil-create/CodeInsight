#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d, n;
    scanf("%d%d", &d, &n);
    if (n == 100)n++; //eg.d=1,n=100でn*100をすると10,000になり、100で2回割れることになるから
    if(d == 0) {
        printf("%d\n", n);
    }
    else if (d == 1) {
        printf("%d\n", n * 100);
    }
    else printf("%d\n", n * 10000);
    return 0;
}