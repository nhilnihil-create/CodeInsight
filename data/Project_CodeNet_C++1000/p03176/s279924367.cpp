#include <bits/stdc++.h>

using namespace std;
long long n,i,val,ans;
vector<long long> seg;
long long h[200005];
long long a[200005];
long long query(long long stt, long long drt, long long st, long long dr, long long p)
{
    if(stt>drt)
        return 0;
    if(stt==st && drt==dr)
        return seg[p];

    int mij=(st+dr)/2;

    if(drt<=mij)
        return query(stt, drt, st, mij, 2*p);
    if(stt>mij)
        return query(stt, drt, mij+1, dr, 2*p+1);

    return max(query(stt, mij, st, mij, 2*p), query(mij+1, drt, mij+1, dr, 2*p+1));
}
void upd(long long i, long long val, long long st, long long dr, long long p)
{
    if(st==dr)
    {
        seg[p]=val;
        return;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
        upd(i, val, st, mij, 2*p);
    else
        upd(i, val, mij+1, dr, 2*p+1);

    seg[p]=max(seg[2*p], seg[2*p+1]);
}
int main()
{
    cin>>n;
    seg.resize(4*n+4);
    for(i=1;i<=n;i++)
        cin>>h[i];
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        val=query(1, h[i]-1, 1, n, 1)+a[i];
        ans=max(ans, val);
        //cout<<i<<' '<<val<<'\n';
        upd(h[i], val, 1, n, 1);
    }

    cout<<ans;
    return 0;
}
