#include <bits/stdc++.h>
using namespace std;

int ua, ta, tp;

int main() {
    scanf("%d%d%d", &ua, &ta, &tp);
    if(ua + ta >= tp || ua + ta == tp - 1) printf("%d\n", ta + tp);
    else printf("%d\n", ua + (2 * ta) + 1);
}