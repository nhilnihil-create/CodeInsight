#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k; cin >> n >> k;
    int tmp;

    if (n % 2 == 0)
        tmp = n/2;
    else
        tmp = n/2 + 1;
    cout << ((k <= tmp) ? "YES" : "NO") << endl;
}