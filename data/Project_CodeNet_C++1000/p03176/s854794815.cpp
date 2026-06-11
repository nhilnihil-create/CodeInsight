#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int n,k;
const int mod = 1e9+7,N=2e5+5;
int h[N];
ll ans[N];
vi adj[N];
ll t[4*N];
void upd(int v,int tl,int tr,int pos,ll val) {
    if (tl == tr) t[v] = val;
    else {
        int tm = (tl + tr)/2;
        if (tm >= pos)
            upd(v*2,tl,tm,pos,val);
        else upd(v*2+1,tm+1,tr,pos,val);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
ll get(int v,int tl,int tr,int l,int r) {
    if (l > tr || r < tl) return 0;
    if (l<=tl && r >= tr) return t[v];
    int tm = (tl + tr)/2;
    return max( get(v*2,tl,tm,l,r), get(v*2+1,tm+1,tr,l,r));
}
int a[N];
main() {
    ios::sync_with_stdio(0);
    cin >> n;
    ll A = 0;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
        ans[i] = a[i] + get(1,1,n,1,h[i]);
        A = max(A,ans[i]);
        upd(1,1,n,h[i],ans[i]);
    }
    cout << A;

}
