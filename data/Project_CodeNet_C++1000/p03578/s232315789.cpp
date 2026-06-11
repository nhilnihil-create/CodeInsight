#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200010
int n, m;
int D[MAX_N], T[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> D[i];
    cin >> m;
    for (int j = 0; j < m; j++) cin >> T[j];
    sort(D, D + n);
    sort(T, T + m);
    int i = 0, j = 0;
    while (i != n && j != m) {
        if (T[j] < D[i]) break;
        else if (T[j] == D[i]) { i++; j++; }
        else i++;
    }
    if (j == m) puts("YES");
    else puts("NO");
}