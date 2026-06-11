#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+7;

int p[MAXN];
int r[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        r[p[i]] = i;
    }

    int ans = 1;
    int run = 1;
    for (int i = 2; i <= n; i++) {
        if (r[i-1] < r[i]) run++;
        else run = 1;
        ans = max(ans, run);
    }

    cout << n-ans << "\n";


    return 0;
}
