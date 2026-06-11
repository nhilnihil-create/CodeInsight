#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

void dump(vector<ll> v) {
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}



int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    int stop = n - 1;
    rep(i, n) if (x[i] >= 0) {
        stop = i;
        break;
    }

    ll mi = 1e10;
    rep(i, stop + 1) {
        int end = i + k;
        if (end <= n) {
            mi = min(mi, 2 * abs(min(0LL, x[i])) + max(0LL, x[end-1]));
            mi = min(mi, abs(min(0LL, x[i])) + 2 * max(0LL, x[end-1]));
        }
    }
    
    put(mi);

    return 0;
}