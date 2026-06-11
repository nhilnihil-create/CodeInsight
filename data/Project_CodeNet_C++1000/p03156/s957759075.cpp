#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, a, b; cin >> n >> a >> b;
    int l = 0;
    int m = 0;
    int u = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p <= a) l++;
        else if (p <= b) m++;
        else u++;
    }
    cout << min({ l,m,u }) << endl;
    return 0;
}