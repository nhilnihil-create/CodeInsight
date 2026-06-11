#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int>v,d;
    f (n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    d = v;
    sort(all(d));
    v.pb(-1e9);
    int mi = 1e9;
    for (int i = 0 ; i < n; i++) {
        vector<int>now;
        vector<int>g;
        for (auto j : v) {
            if (j < d[i]) {
                sort(all(now));
                for (int l = 0 ; l < (int)now.size() - k + 1 ; l++) {
                    g.pb(now[l]);
                }
                now.clear();
            }
            else {
                now.pb(j);
            }
        }
        if ((int)g.size() >= q) {
            sort(all(g));
            mi = min(mi, g[q - 1] - g[0]);
        }
    }
    cout << mi << '\n';
}