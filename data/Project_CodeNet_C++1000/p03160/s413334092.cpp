/*
 Akhil Saini
 DP : Atcoder DP Series Problem 1 : Frog 1
*/
#include<bits/stdc++.h>
using namespace std;
#define f0(i,n)            for(i=0;i<n;i++)
#define flast(i,n)         for(i=n-1;i>=0;i--)
#define f1(i,n)            for(i=1;i<=n;i++)
#define f(i,a,n)           for(i=a;i<=n;i++)
#define fit(v)             for(auto itr=v.begin();itr!=v.end();itr++)
#define ump(a,b)           unordered_map<a,b>
#define ll                 long long int
#define endl               "\n"
#define fir                first
#define sec                second
#define pb                 push_back
#define bp                 __builtin_popcount
#define bit()              bitset<62>(x).to_string()
#define binstr_to_num(x)   stoll(x,nullptr,2)
#define mod                1000000007
#define inf                1e18+1
#define all(v)             v.begin(),v.end()
#define debug              cout<<"Hello"<<endl
typedef                    vector<ll> vll;
const double pi=acos(-1.0);

//You can only take 1 or 2 steps then in
//how many ways you can reach to the nth stairs.

ll dp[1000001];
vector<ll> v;

//Function to store ans of each stairs. 
ll dp_function(ll n)
{
    if(n==0)
    return 0;
    if(n==1)
    return abs(v[0]-v[1]);

    if(dp[n]!=-1) return dp[n];

    dp[n]=min(dp_function(n-1)+abs(v[n-1]-v[n]),dp_function(n-2)+abs(v[n-2]-v[n]));
    return dp[n];
}

void solve()
{
    ll n,x,i;
    cin>>n;
    v.clear();
    f0(i,n) { cin>>x; v.push_back(x); }
    cout<<dp_function(n-1)<<endl;
}

void fast()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

int main()
{
    fast();
    int t=1,i;
    f1(i,1000000) dp[i]=-1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}