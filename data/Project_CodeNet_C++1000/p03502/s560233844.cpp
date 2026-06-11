#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll n;
int main() {
    cin >> n;
    ll m = n;
    int sum = 0;
    while (n) {
        int r = n % 10;
        sum += r;
        n /= 10;
    }
    if (m % sum == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
