#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i <= n - 1; i++) cin >> v[i];
    int maior = 0;
    int ind = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (v[i] > maior) {
            maior = v[i];
            ind = i;
        }
    }
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (i != ind) tot += v[i];
    }
    if (maior < tot) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}