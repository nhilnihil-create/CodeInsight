#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, temp, ans=0;
    cin >> n;
    int v[n];

    for (int i = 0 ; i < n ; ++i) {
        cin >> v[i];
    }

    for (int i = 0 ; i < n ; ++i) {
        cin >> temp;
        v[i] -= temp;
        if (v[i] > 0) ans += v[i];
    }

    cout << ans; 

    return 0;
}
