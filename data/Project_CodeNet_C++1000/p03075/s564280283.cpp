#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int a[5];
    int k;
    rep(i,5) cin >> a[i];
    cin >> k;

    sort(a, a+5);
    if (a[4]-a[0] <= k) cout << "Yay!" << endl;
    else cout << ":(" << endl;;    
    return 0;
}