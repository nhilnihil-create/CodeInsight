#include <bits/stdc++.h>
using namespace std;

const long long INF=1e12;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<long long> s(a+1),t(b+1);
    s[0]=-INF;
    t[0]=-INF;
    for ( int i=1; i<=a; i++ ) {
        cin >> s[i];
    }
    for ( int i=1; i<=b; i++ ) {
        cin >> t[i];
    }
    s.push_back(INF);
    t.push_back(INF);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    while ( q-- ) {
        long long x;
        cin >> x;
        int ai=lower_bound(s.begin(), s.end(), x)-s.begin();
        int bi=lower_bound(t.begin(), t.end(), x)-t.begin();
        long long sx[2], tx[2];
        sx[1]=s[ai]; sx[0]=s[ai-1];
        tx[1]=t[bi]; tx[0]=t[bi-1];
        long long ans=INF;
        for ( int i=0; i<2; i++ ) {
            for ( int j=0; j<2; j++ ) {
                ans=min(ans, abs(x-sx[i])+abs(sx[i]-tx[j]));
                ans=min(ans, abs(x-tx[j])+abs(tx[j]-sx[i]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}