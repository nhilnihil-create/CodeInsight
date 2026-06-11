#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define N 200005
int seg[4*N];

void update(int st, int l, int r, int idx, int val)
{
    if(l == r)
    {
        seg[st] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid)
        update(2*st+1, l, mid, idx, val);
    else
        update(2*st+2,mid+1, r, idx, val);
    seg[st] = max(seg[2*st+1],seg[2*st+2]);    
}
int query(int st, int l, int r, int ql, int qr)
{
    if(l > qr || r < ql)
    {
        return 0;
    }
    if(l >= ql && r <= qr)
        return seg[st];
    int mid = (l+r)/2;
    return max(query(2*st+1, l, mid, ql, qr), query(2*st+2, mid+1, r, ql, qr));
}
signed main() {
    int n;
    cin >> n;
    int h[n], a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
        h[i]--;
    }
    for(i=0;i<n;i++)
        cin >> a[i];
    int dp[n];
    dp[0] = a[0];
    update(0, 0, n-1, h[0], dp[0]);
    for(i=1;i<n;i++)
    {
        int mx = query(0, 0, n-1, 0, h[i]);
        dp[i] = a[i] + mx;
        update(0, 0, n-1, h[i], dp[i]);
    }
    cout << *max_element(dp, dp+n);
}