#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <=3; i++) {
        if((a * b * i) % 2 != 0) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}