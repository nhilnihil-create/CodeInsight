#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n;

int main() {
    cin >> n;
    unordered_set<int> seen;
    int i = 1;
    while (1) {
        if (seen.count(n)) break;
        seen.insert(n);
        ++i;
        if (n & 1) n = n * 3 + 1;
        else  n = n / 2;
    }
    cout << i << endl;
    return 0;
}
