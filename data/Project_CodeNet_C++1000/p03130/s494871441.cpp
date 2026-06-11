#include <bits/stdc++.h>
using namespace std;
int main () {
    map<int, int> m;
    for (int i = 0; i < 6; i++) {
        int a;
        cin >> a;
        if (++m[a] > 2) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}