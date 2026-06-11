#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    if ((b - a) & 1) printf("Borys\n");
    else printf("Alice\n");
    return 0;
}