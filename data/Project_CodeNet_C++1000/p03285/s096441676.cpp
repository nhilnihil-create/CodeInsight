#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n / 4; i++) {
        for(int j = 0; j <= n / 7; j++) {
            if(4 * i + 7 * j == n) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}