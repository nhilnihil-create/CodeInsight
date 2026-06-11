
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    int v1 = abs(a - b) + abs(a - c);
    int v2 = abs(b - a) + abs(b - c);
    int v3 = abs(c - b) + abs(a - c);
    cout << min(min(v1, v2), v3) << endl;

    return 0;
}

