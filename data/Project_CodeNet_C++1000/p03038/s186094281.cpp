//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 1e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,m,a[N];
pair<int,int> x[N];
ll sum = 0;

void init() {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < m; ++j) {
        cin >> x[j].s >> x[j].f;
    }

    int i = 0, cur = 0;

    sort(a,a+n);
    sort(x,x+m);
    reverse(x,x+m);

    while(i<n && cur<m) {

        if(x[cur].s) {

            a[i] = max(a[i], x[cur].f);
            ++i;
            if(!(--x[cur].s)) ++cur;

        }

    }

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    cout << sum << '\n';

    return 0;
}