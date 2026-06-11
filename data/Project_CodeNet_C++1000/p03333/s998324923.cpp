#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

void cxxio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll solve(const vpii& ps) {
    int n=ps.size();
    vpii L(n), R(n);
    forn(i, n) {
        L[i]=pii(ps[i].ff, i);
        R[i]=pii(ps[i].ss, i);
    }
    sort(all(L));
    sort(all(R));
    reverse(all(L));
    vi used(n);
    ll ans=0, pos=0;
    auto move=[&](pii p) {
        if (pos<p.ff) {
            ans+=llabs(p.ff-pos);
            pos=p.ff;
        }
        if (pos>p.ss) {
            ans+=llabs(p.ss-pos);
            pos=p.ss;
        }
    };
    for (int i=0, j=0;;) {
        for (; i<n && used[L[i].ss]; i++);
        if (i==n) break;
        move(ps[L[i].ss]);
        used[L[i].ss]=1;
        for (; j<n && used[R[j].ss]; j++);
        if (j==n) break;
        move(ps[R[j].ss]);
        used[R[j].ss]=1;
    }
    return ans+llabs(pos);
}

int main() {
    cxxio();
    int n;
    cin>>n;
    vpii ps(n);
    forn(i, n) cin>>ps[i].ff>>ps[i].ss;
    ll ans=solve(ps);
    forn(i, n) ps[i]=pii(-ps[i].ss, -ps[i].ff);
    ans=max(ans, solve(ps));
    cout<<ans<<'\n';
}
