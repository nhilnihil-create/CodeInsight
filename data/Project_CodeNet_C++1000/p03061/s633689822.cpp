#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

vector<ll> tree;
vector<ll> arr;
void build_tree (ll start, ll end, ll node)
{
    if (start==end)
    {
        tree[node]=arr[start];
        return;
    }
    else
    {
        ll mid=(start+end)/2;
        build_tree(start,mid,2*node);
        build_tree(mid+1,end,2*node+1);
        tree[node]=__gcd(tree[2*node],tree[2*node+1]);
        return;
    }
}

ll query (ll l, ll r, ll start, ll end, ll node)
{
    if (l<=r)
    {
        if ((l<=start)&&(end<=r))
        {
            return tree[node];
        }
        else if ((end<l)||(r<start))
        {
            return arr[l];
        }
        else
        {
            ll mid=(start+end)/2;
            return __gcd(query(l,r,start,mid,2*node),query(l,r,mid+1,end,2*node+1));
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll n;
    cin >> n;
    arr.resize(n);
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    tree.resize(4*n);
    build_tree(0,n-1,1);

    ll ans=LLONG_MIN;
    for (ll i=0;i<=n-1;i++)
    {
        ll gcd_first=query(0,i-1,0,n-1,1);
        ll gcd_second=query(i+1,n-1,0,n-1,1);

        ll local;
        if ((gcd_first!=-1)&&(gcd_second!=-1))
        {
            local=__gcd(gcd_first,gcd_second);
        }
        else if (gcd_first==-1)
        {
            local=gcd_second;
        }
        else if (gcd_second==-1)
        {
            local=gcd_first;
        }

        ans=max(ans,local);
    }

    cout << ans << endl;
    return 0;
}