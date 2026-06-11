#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, h, a, b;
    cin >> n >> h;
    vector<ll> starts, ends;
    for (ll i=0; i<n; i++) {
        cin >> a >> b;
        starts.push_back(a);
        ends.push_back(b);
    }
    sort(starts.rbegin(),starts.rend());
    sort(ends.rbegin(),ends.rend());
    ll ei = 0;
    ll res = 0;
    while (h>0) {
        if (starts[0]>=ends[ei] || ei==n) {
            res+=h/starts[0];
            if (h%starts[0]!=0) res++;
            h = 0;
        }
        else {
            res++;
            h-=ends[ei];
            ei++;
        }
    }
    cout << res;
    return 0;
}