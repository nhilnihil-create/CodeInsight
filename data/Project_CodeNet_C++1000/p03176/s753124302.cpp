#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<ll> tree(4*N,0);

void update(int idx,int l,int r,int pos,ll val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> a[i];
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll now=query(1,1,n,1,h[i]-1)+a[i];
        res=max(res,now);
        update(1,1,n,h[i],now);
    }
    cout << res << "\n";
    return 0;
}
