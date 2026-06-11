#include<bits/stdc++.h>
using namespace std;

#define make_it_fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define imn INT_MIN
#define imx INT_MAX

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 20
#endif

ll power(ll a,ll b)
{
    if(b==1)
    return a;
    if(b==0)
    return 1;
    ll ret=power(a,b/2);
    ret=(ret*ret);
    if(b&1)
    ret=(ret*a);
    return ret;
}

ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}

void solve()
{
    ll n,k,i,j;
    cin>>n>>k;
    ll a[n];
    vector<ll> dp(k+1,2);
    for(i=0;i<n;i++)
    cin>>a[i];
    ll flag=0;
    for(i=1;i<=k;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                if(dp[i-a[j]]==2)
                {
                    dp[i]=1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        continue;
    }
    if(dp[k]==1)
    cout<<"First"<<endl;
    else
    cout<<"Second"<<endl;
}
int main()
{
    int TEST_CASES=1;
    // cin>>TEST_CASES;
    while(TEST_CASES--)
    {
        solve();
    }
    return 0;
}
