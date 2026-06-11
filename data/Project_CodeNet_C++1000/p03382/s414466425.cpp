#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sd second
#define ll long long
#define pli pair<ll,int>

using namespace std;

const int maxn = 500010;
const int maxk = 5010;
const ll oo = 1e9+7;

int m,n,a[maxn],s[maxn],num[maxn],id[maxn];

int cmp (int x,int y) {
    return a[x] < a[y];
}

int main() {
   // freopen("in.txt","r",stdin);
    cin>>n;
    int mx = 0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    cout<<mx<<" ";
    int pv = mx;
    mx =0;
    for (int i=1;i<=n;i++)
        if (a[i] <= pv/2 ) mx = max(mx,a[i]);
    mx = pv - mx;
    bool use = false;
    for (int i=1;i<=n;i++)
        if (a[i] >= pv/2 && a[i] < mx) {
            mx = min(mx,a[i]);
            use = true;
        }
    if (use) cout<<mx;
    else cout<<pv-mx;

}
