#include <bits/stdc++.h>
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 111111;
int a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cin >> n;
    int x = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        x = max(x, a[i]);
    }
    int y = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i] == x) continue;
        if(abs(x / 2 - a[i]) < abs(x / 2 - y)) {
            y = a[i];
        }
    }
    cout << x << " " << y << endl;
    return 0;
}