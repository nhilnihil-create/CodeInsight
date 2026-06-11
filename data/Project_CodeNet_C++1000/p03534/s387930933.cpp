#include <iostream>
#include <algorithm>
using namespace std;
#define FAIL { cout << "NO\n"; return 0; }

int main() {
    int a[3] = {}, i, N = 0;
    char c;

    while (cin >> c) {
        if (c == '=') break;
        a[(int)(c-'a')]++;
        N++;
    }
    sort(a, a+3, greater<int>()); // descending

    for (i = 0; i < 3; i++) {
        if (1+i+3*(a[i]-1) > N) FAIL;
    }
    cout << "YES\n";
}