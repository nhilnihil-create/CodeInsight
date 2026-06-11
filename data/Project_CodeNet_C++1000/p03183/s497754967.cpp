#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define vi vector <int>
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define tiii tuple <int,int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector <vector <int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 20001
#define mod 1000000007
#define mod2 998244353
#define inf 1e17


int dp[N];
piii a[1001]; // weight , stack,value


bool cmp(piii a,piii b)
{
    return (a.ff+a.ss.ff)<(b.ff+b.ss.ff);
}


int32_t main()  
{
    boost
    // #ifndef ONLINE_JUDGE 
    // NAYAN
    // #endif

    int n;
    cin >> n;
    int i,j;

    
    for(i=1;i<=n;i++)
    {
        cin >> a[i].ff >> a[i].ss.ff >> a[i].ss.ss;
    }

    sort(a+1,a+n+1,cmp);

    for(i=1;i<=n;i++)
    {
        int w,s,v;
        w=a[i].ff;
        s=a[i].ss.ff;
        v=a[i].ss.ss;
        for(j=N-1;j>=0;j--)
        {
            if(j<=s)
            {
                dp[j+w]=max(dp[j+w],dp[j]+v);
            }
        }
    }


    

    int ans=0;

    for(i=0;i<N;i++)
    {
        ans=max(ans,dp[i]);
    }

    cout << ans;

    

    
}