#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
    int a = n / 10000;
    n %= 10000;
    int b = n / 1000;
    n %= 1000;
    int c = n / 100;
    n %= 100;
    int d = n / 10;
    n %= 10;
    return a+b+c+d+n;
}

int main() {
    int n;
    scanf("%d",&n);
    int h = n / 2;
    int ans = 1000;
    for(int i = 1; i <= h; i++) {
        int x = i;
        int y = n - x;
        int counter = digit_sum(x) + digit_sum(y);
        ans = min(ans,counter);
    }
    printf("%d\n",ans);
}