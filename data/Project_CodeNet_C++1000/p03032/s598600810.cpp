#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[100];
ll dp[55][55][105];
ll recur(int l,int r,int rem,ll p,ll n,int cnt,vector<ll>&v)
{
    //  cout<<l<<" "<<r<<" "<<rem<<" "<<p<<" "<<n<<endl;
    if(l>r)
    {
        priority_queue<int>pq;
        int sz=v.size();
        for(int i=0; i<sz; i++)
        {
            if(v[i]<0)
                pq.push(v[i]*-1);
        }
        int ans=p+n,k=rem;
        while(!pq.empty() && k--)
        {

            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
    if(rem==0)
    {
        // cout<<l<<" "<<r<<" "<<" "<<p<<" "<<n<<" "<<p+n<<endl;
        return p+n;
    }
    ll &ret=dp[l][r][rem];
    if(~ret)
        return ret;
    ret=max(ret,p+n);
    if(cnt>=rem)
    {
        priority_queue<ll>pq;
        int sz=v.size();
        for(int i=0; i<sz; i++)
        {
            if(v[i]<0)
                pq.push(v[i]*-1);
        }
        ll ans=p+n,k=rem;
        while(!pq.empty() && k--)
        {

            ans+=pq.top();
            pq.pop();
        }
        ret=max(ret,ans);
    }
    ll x=0,y=0;
    if(arr[l]<0)
        y=arr[l];
    else
        x=arr[l];
    v.push_back(arr[l]);
    ret=max(ret,recur(l+1,r,rem-1,p+x,n+y,cnt+(arr[l]<0),v));
    x=0,y=0;
    v.pop_back();

    if(arr[r]<0)
        y=arr[r];
    else
        x=arr[r];
    v.push_back(arr[r]);
    ret=max(ret,recur(l,r-1,rem-1,p+x,n+y,cnt+(arr[r]<0),v));
    v.pop_back();
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,moves;
    cin>>n>>moves;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    vector<ll>v;

    cout<<recur(0,n-1,moves,0,0,0,v)<<endl;


    return 0;
}
