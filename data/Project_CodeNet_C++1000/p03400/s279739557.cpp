#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d, x, temp;
    cin >> n >> d >> x;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        for(int j = 1; j <= d;) {
            x++;
            j += temp;
        }
    }
    cout << x << endl;
    return 0;
}
