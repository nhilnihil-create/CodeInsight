#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    char op[] = {'+', '-'};
    int n4 = n % 10;
    n /= 10;
    int n3 = n % 10;
    n /= 10;
    int n2 = n % 10;
    n /= 10;
    int n1 = n % 10;
    n /= 10;

    if(n1 + n2 + n3 + n4 == 7)
        printf("%d+%d+%d+%d=7\n", n1, n2, n3, n4);
    else if(n1 + n2 + n3 - n4 == 7)
        printf("%d+%d+%d-%d=7\n", n1, n2, n3, n4);
    else if(n1 + n2 - n3 + n4 == 7)
        printf("%d+%d-%d+%d=7\n", n1, n2, n3, n4);
    else if(n1 + n2 - n3 - n4 == 7)
        printf("%d+%d-%d-%d=7\n", n1, n2, n3, n4);
    else if(n1 - n2 + n3 + n4 == 7)
        printf("%d-%d+%d+%d=7\n", n1, n2, n3, n4);
    else if(n1 - n2 + n3 - n4 == 7)
        printf("%d-%d+%d-%d=7\n", n1, n2, n3, n4);
    else if(n1 - n2 - n3 + n4 == 7)
        printf("%d-%d-%d+%d=7\n", n1, n2, n3, n4);
    else if(n1 - n2 - n3 - n4 == 7)
        printf("%d-%d-%d-%d=7\n", n1, n2, n3, n4);
}