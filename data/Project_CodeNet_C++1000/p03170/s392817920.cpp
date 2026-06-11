#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXK 100001
bool win[MAXK];
int main() {
    memset(win, false, sizeof(win));
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a[j]) {
                win[i] += !win[i - a[j]];
            }
        }
    }
    if (win[k]) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
    return 0;
}