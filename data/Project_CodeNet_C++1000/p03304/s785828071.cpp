#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    if (d == 0) {
        cout << setprecision(12) << 1.0 * (n - d) / n / n * (m - 1) << endl;
    } else {
        cout << setprecision(12) << 2.0 * (n - d) / n / n * (m - 1) << endl;
    }
}