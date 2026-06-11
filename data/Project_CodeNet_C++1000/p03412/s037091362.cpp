#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n,a[maxn],b[maxn],ans=0;

int fin(int x) {
    int lo=0,hi=n;
    while (lo<hi) {
        int mi = (lo+hi+1)/2;
        if (b[mi]<=x) lo=mi;
        else hi=mi-1;
    }
    return lo;
}

int query(int l,int r) {
    return fin(r) - fin(l-1);
}

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int k=28;k>=0;k--) {
        int tt = 1<<k;
        for (int i=1;i<=n;i++) {
            a[i] = a[i] & (2*tt-1);
            b[i] = b[i] & (2*tt-1);
        }
        sort(b+1,b+n+1);
        for (int i=1;i<=n;i++) {
            int sum = query(tt - a[i], 2*tt-1-a[i]) + query(3*tt-a[i], 4*tt-1-a[i]);
            if (sum%2) ans^=tt;
        }
    }
    cout<<ans<<endl;
}
