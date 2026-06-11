#include<bits/stdc++.h>
using namespace std;
typedef pair< int , int >PII;

vector< PII >edg[27];

int main() {
    int L;
    cin >> L;

    int n = 20, m = 0;
    for (int i = 2; i <= 20; i++) {
        edg[i-1].emplace_back(i, 0);
        m++;
    }

    int msb = 31-__builtin_clz(L);
    for (int i = 0; i < msb; i++) {
        edg[20-i-1].emplace_back(20-i, 1<<i);
        m++;
    }

    int now = 1<<msb;
    for (int i = msb-1; i >= 0; i--) {
        if (L&(1<<i)) {
            edg[1].emplace_back(20-i, now);
            now |= 1<<i;
            m++;
        }
    }

    cout << n << " " << m << endl;
    for (int i = 1; i < 20; i++) {
        for (PII p : edg[i]) {
            cout << i << " " << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
