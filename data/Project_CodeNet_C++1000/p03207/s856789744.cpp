#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    int mx = 0;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        sm += p;
        mx = max(mx, p);
    }
    cout << sm - mx / 2;
    return 0;
}
