#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;cin>>n;
    bool ok = 1;
    int ct=0, cx=0, cy=0;
    while(n--) {
        int t, x, y;
        cin>>t>>x>>y;
        int d = abs(x-cx) + abs(y-cy);
        int dt = t-ct;
        if(d > (t-ct) || ((t-ct)-d)%2==1) {
            ok = 0;
        }
        ct = t;
        cx = x;
        cy = y;
    }
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}