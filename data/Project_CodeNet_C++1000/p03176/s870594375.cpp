#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define N 100005
#define inf 1e18
#define mem(a,b) memset(a,b,sizeof(a))
#define all(v) v.begin(),v.end()

using namespace std;

ll binomialCoeff(ll n,ll k)
{
    ll res = 1;
    if(k >n - k)
        k = n - k;
    for(int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}


ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void Sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

//***************************************************************************************************************************//

const int num = 1e6 + 1e4;
ll fen[num];

void update(int i,ll add)
{
    while(i<num)
    {
        fen[i] = max(fen[i],add);
        i += (i&(-i));
    }
}

ll sum(int i)
{
    ll s =0;
    while(i>0)
    {
        s = max(s,fen[i]);
        i -= (i&(-i));
    }
    return s;
}

int lowerbound(int k)
{
    int low = 0 , ans = 0 , prevsum = 0;
    for(int i=19;i>=0;i--)
    {
        if((low + (1<<i))<num && (fen[low + (1<<i)] + prevsum) < k)
        {
            ans = low + (1<<i);
            low = ans;
            prevsum += fen[low];
        }
    }
    return ans+1;
}

//SEGMENT TREE
ll tree[4*N+1];

void buildtree(int node,int start,int end)
{
    if(start == end)
        tree[node] = tree[start];
    else
    {
        int mid = (start+end)/2;
        buildtree(2*node,start,mid);
        buildtree(2*node + 1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

void update(int node,int start,int end,int index,ll value)
{
    if(start == end)
        tree[node] = max(tree[node],value);
    else
    {
        int mid = (start+end)/2;
        if(start <= index && index <= mid)
        {
            update(2*node,start,mid,index,value);
        }
        else
        {
            update(2*node + 1,mid+1,end,index,value);
        }
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}

ll query(int node,int start,int end,int l,int r)
{
    if(r < start || end < l)
    {
        //completely outside range
        return 0;
    }
    if(l <= start && end <= r)
    {
        //completely inside
        return tree[node];
    }
    //partially inside
    int mid = (start + end)/2;
    ll p1 = query(2*node,start,mid,l,r);
    ll p2 = query(2*node + 1,mid+1,end,l,r);
    return max(p1,p2);
}

int main()
{
    int n;
    cin >> n;
    int h[n];
    ll b[n];
    for(int i=0;i<n;i++)
        cin >> h[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    /*ll dp[n];
    for(int i=0;i<n;i++)
    {
        int hh = h[i];
        ll bb = b[i];
        ll val = sum(hh-1);
        update(hh,val + bb);
    }
    cout << sum(n);*/
    for(int i=0;i<n;i++)
    {
        int hh = h[i];
        ll bb = b[i];
        ll val = query(1,1,2*N,1,hh-1);
        update(1,1,2*N,hh,val+bb);
    }
    cout << query(1,1,2*N,1,n);
}

