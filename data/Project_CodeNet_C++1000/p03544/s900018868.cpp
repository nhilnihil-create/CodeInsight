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

const int N = 87;
ll a[N];
int n;

int main() {
    a[0] = 2;
    a[1] = 1;
    for (int i = 2; i <= N; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cin >> n;
    cout << a[n] << endl;
    return 0;
}
