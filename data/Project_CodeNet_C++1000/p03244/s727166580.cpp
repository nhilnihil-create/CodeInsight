#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int n;
int v[100100];
int cnt1[100100], cnt2[100100];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    rep(i, n) cin >> v[i];
    for (int i=0; i<n; i+=2) cnt1[v[i]]++;
    for (int i=1; i<n; i+=2) cnt2[v[i]]++;
    vector<P> v1, v2;
    rep(i, 100100) v1.pb(P(n/2-cnt1[i], i));
    rep(i, 100100) v2.pb(P(n/2-cnt2[i], i));
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1[0].second!=v2[0].second) cout << v1[0].first+v2[0].first << endl;
    else cout << min(v1[0].first+v2[1].first, v1[1].first+v2[0].first) << endl;
}