#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0) {
        cout << -1 << endl;
    }
    else cout << a << endl;
    return 0;
}
