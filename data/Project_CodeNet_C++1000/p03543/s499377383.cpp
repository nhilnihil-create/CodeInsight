#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string n;
    int co = 1;
    cin >> n;
    int tmp = n[0];
    for (int i = 1; i < 4; ++i) {
        if (tmp == n[i])
            co++;
        if (co >= 3)
            break;
        if (tmp != n[i]) {
            tmp = n[i];
            co = 1;
        }
    }
    if (co >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}