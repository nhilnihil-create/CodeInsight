/*Remember: The Struggle is Important*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     ld           long double
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     pii          pair<int,int>
#define     F            first
#define     S            second
#define     mt           make_tuple
#define     show(x)      for(auto c:x)cout<<c<<" ";cout<<"\n";
#define     show2(x)     for(auto c:x)cout<<c.F<<" "<<c.S<<"\n";

const int inf=1e18,M=1e9+7;
const int N=3e3+10;

vector<vector<ld>> dp(N,vector<ld>(N,-1));       // (index, heads till now)

vector<ld> p;
int n;

ld rec(int ind,int h)
{
    if(ind==-1)
        return h>(n/2);

    if(dp[ind][h]!=-1)
        return dp[ind][h];

    ld res=0;
    res=( (1-p[ind])*rec(ind-1,h) + p[ind]*rec(ind-1,h+1) );

    //cout<<ind<<" "<<h<<" "<<res<<"\n";

    return (dp[ind][h]=res);
}

void solve()
{
    cin>>n;

    p.resize(n);
    for(int i=0;i<n;++i)
        cin>>p[i];

    ld ans=rec(n-1,0);

    cout<<fixed<<setprecision(10)<<ans;
}

int32_t main()
{
    //fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}


