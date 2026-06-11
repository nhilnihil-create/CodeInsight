#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, a, sum = 0;
    cin >> n >> a;
    while (1) {
        if (n % 500 == 0)
            break;
        n--;
        sum++;
    }
    if (sum <= a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}