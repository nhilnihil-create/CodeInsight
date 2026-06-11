#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    int v[51];
    int c[51];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    int s = 0;
    for (int i=0; i< n; i++) {
        int diff = v[i] - c[i];
        if (diff > 0) {
            s += diff;
        }
    }
    cout << s << endl;
    return 0;
}