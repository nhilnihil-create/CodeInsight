#include <bits/stdc++.h>
#define lli long long int
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)
using namespace std;
lli query(lli index,lli l,lli r,lli cl,lli cr,lli a[])
{
    if(l>cr||cl>r)
    return 0;
    if(cl<=l&&r<=cr)
    return a[index];
    lli mid=(l+r)/2;
    return max(query(index*2,l,mid,cl,cr,a),query(2*index+1,mid+1,r,cl,cr,a));
}
lli update(lli index,lli l,lli r,lli h,lli val,lli a[])
{
    if(l==r){
    return a[index]=max(a[index],val);}
    lli mid=l+r;
    mid/=2;
    if(h<=mid)
    a[index]=max(update(2*index,l,mid,h,val,a),a[index]);
    else
    a[index]=max(update(2*index+1,mid+1,r,h,val,a),a[index]);
}
int main()
{
    lli  n;
    s(n);
    lli a[4*n+1]={0};
    lli h[n+1]={0};
    lli val[n+1]={0};
    rep(i,n){
    s(h[i+1]);}
    rep(i,n){
    s(val[i+1]);}
    vector<lli>b(n+2);
    reps(f,1,n+1)
    {
        b[f]=val[f]+query(1,1,n,0,h[f]-1,a);
        update(1,1,n,h[f],b[f],a);
    }
    cout<<query(1,1,n,1,n,a);
    return 0;
}