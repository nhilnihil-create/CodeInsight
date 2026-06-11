/* Ajay Jadhav */
#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int N=2e5+5;
long long f[N],h[N],v[N],n;

void update(int idx,long long val)
{
    for(;idx<N;idx+=(idx&-idx)) 
        f[idx]=max(val,f[idx]);
}

long long query(int idx)
{
    long long s=0;
    for(;idx; idx-=(idx&-idx))
        s=max(s,f[idx]);
    return s;
}

void solve()
{
    cin>>n;
    rep(i,0,n) cin>>h[i];
    rep(i,0,n) cin>>v[i];
    rep(i,0,n)
    {
        ll temp=query(h[i]-1)+v[i];
        update(h[i],temp);
    }
    cout<<query(N-1);
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}