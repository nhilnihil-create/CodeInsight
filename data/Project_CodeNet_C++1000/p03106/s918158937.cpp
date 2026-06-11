#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int count = 0;
    for(int i = min(a, b); i > 0; i--) {
        if( a % i == 0 && b % i == 0) {
            count++;
            if(count == k) printf("%d\n", i);
        }
    }
    return 0;
}