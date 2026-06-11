#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, z, w;
    scanf("%d%d%d", &n, &z, &w);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a.at(i));
    if (n == 1) printf("%d\n", abs(w - a.front()));
    else printf("%d\n", max(abs(a.at(n - 1) - a.at(n - 2)), abs(w - a.at(n - 1))));
    return 0;
}
