#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
const int k=100010;
const int maxn=200020;
int seg[5000010];
int a[100010];
int a2[100010];
int b[100010];

void postavi(int t, int l, int r)
{
    seg[t]=0;
    if(l==r) return;
    int mid=(l+r)/2;
    postavi(2*t,l,mid);
    postavi(2*t+1,mid+1,r);
}

void update(int t, int l,int r, int x)
{
    seg[t]++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(x<=mid) update(2*t,l,mid,x);
    else update(2*t+1,mid+1,r,x);
}

ll sum(int t, int l, int r, int L, int R)
{
    if(l>R || L>r)
        return 0;
    if(l>=L && r<=R)
        return seg[t];
    int mid=(l+r)/2;
    return sum(2*t,l,mid,L,R)+sum(2*t+1,mid+1,r,L,R);
}

ll cnt(int br)
{
    ll sol=0;
    for(int i=0;i<n;i++)
        if(a[i]>=br) b[i]=1;
        else b[i]=-1;
    for(int i=1;i<n;i++)
        b[i]+=b[i-1];
    postavi(1,1,maxn);
    update(1,1,maxn,k);
    for(int i=0;i<n;i++)
    {
        sol+=sum(1,1,maxn,1,b[i]+k);
        update(1,1,maxn,b[i]+k);
        //if(a[i]>=br && i>0) sol++;
    }
    return sol;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++)
        cin>>a[i];

	for(int i=0;i<n;i++)
        a2[i]=a[i];

    sort(a2,a2+n);

    int l=0;
    int r=n-1;
    ll m=(n*(n+1))/2;

    /*cout<<m<<" "<<(m+1)/2<<endl;
    for(int i=0;i<n;i++)
        cout<<a2[i]<<" "<<cnt(a2[i])<<endl;*/

    while(l<r)
    {
        int sr=(l+r+1)/2;
        if(cnt(a2[sr])>=(m+1)/2)
            l=sr;
        else
            r=sr-1;
    }

    cout<<a2[l];

	return 0;
}
