#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define llong long long int
#define ullong unsigned long long int
#define rep(i, n) for (int i = 0; i < n; ++i);

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong n, p;
    cin >> n >> p;

    unordered_map<llong, llong> UM;
    llong i = 2;
    while(i * i <= p) {
        if (p % i == 0) {
            ++UM[i];
            p /= i;
        } else {
            ++i;
        }
    }

    if (p != 1) ++UM[p];
    llong ans = 1;
    for (unordered_map<llong, llong>::iterator itr = UM.begin(); itr != UM.end(); ++itr) {
        ans *= pow(itr->first, itr->second / n);
    }

    cout << ans << endl;

    return 0;
}