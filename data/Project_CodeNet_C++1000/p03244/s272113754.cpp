#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100100

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> va(MAX_N), vb(MAX_N);
    for (int i = 0; i < n; i+=2) va[v[i]]++, vb[v[i+1]]++;

    int na1, ca1 = 0, nb1, cb1 = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (ca1 < va[i]) {
            na1 = i;
            ca1 = va[i];
        }
        if (cb1 < vb[i]) {
            nb1 = i;
            cb1 = vb[i];
        }
    }
    int ans = n - ca1 - cb1;
    if (na1 == nb1) {
        int ca2 = 0, cb2 = 0;
        for (int i = 0; i < MAX_N; i++) {
            if (ca2 < va[i] && na1 != i) ca2 = va[i];
            if (cb2 < vb[i] && nb1 != i) cb2 = vb[i];
        }
        ans = min(n - ca1 - cb2, n - cb1 - ca2); 
    }
    cout << ans << endl;
    return 0;
}