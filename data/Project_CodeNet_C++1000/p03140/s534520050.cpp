#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] != c[i]) {
                t++;
            }
        } else if (a[i] == c[i]) {
            t++; 
        } else if (b[i] == c[i]) {
            t++;
        } else {
            t += 2;
        }
    }
    cout << t << endl;

}
