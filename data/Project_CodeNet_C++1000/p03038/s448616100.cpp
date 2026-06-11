#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool comp2r(P a, P b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<P> p(m);
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        p[i] = make_pair(b, c);
    }
    
    sort(a.begin(), a.end());
    sort(p.begin(), p.end(), comp2r);
    
    vector<ll> s(n+1);
    s[0] = 0;
    for (int i = 0; i < n; i++)
        s[i+1] = s[i] + a[i];
    ll total = s[n];
    int mi = a[0];
    int del = 0;
    bool endflag = false;
    for (int i = 0; i < m && !endflag; i++) {
        int b = p[i].first, c = p[i].second;
        auto it = lower_bound(a.begin(), a.end(), c);
        int pos = it - a.begin();
        if (del + b > pos)
            b = pos - del;
        if (del + b >= n) {
            b = n - del;
            endflag = true;
        }
        if (mi < c) {
            total -= s[b + del] - s[del];
            total += (ll)c * b;
            del += b;
            mi = a[del];
        }
        else
            endflag = true;
    }
    
    cout << total << endl;
    
    return 0;
}
