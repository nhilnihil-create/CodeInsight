#include <bits/stdc++.h>

using namespace std;

int a, b, c, ans    ;

int main () {
    scanf("%d%d%d", &a, &b, &c);
    int val = min (b, c);
    ans += val * 2;
    b -= val;
    c -= val;
    if (b)ans += b;
    else ans += min (a + 1, c);
    cout << ans;
}
