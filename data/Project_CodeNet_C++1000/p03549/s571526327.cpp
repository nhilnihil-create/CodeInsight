#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int n, m; cin >> n >> m;
    int time = 1900 * m + 100 * (n - m);
    int Ecnt = 1;
    while (m--) {
        Ecnt *= 2;
    }
    cout << time * Ecnt << endl;
    return 0;
}