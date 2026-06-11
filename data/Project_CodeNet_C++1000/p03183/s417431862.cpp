// #pragma GCC optimize("Ofast") 
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;


#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define sz(c) c.size()
#define int ll
#define rep(i,j,x) for(int i=j;i<x;i++)
#define repn(i,j,x) for(int i=j;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())


template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }
 
double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

// Removes leading zeroes from answer, or outputs one '0' if s is all zeroes
void outputAnswer(string s) {
    cout<<regex_replace(s, regex("^0+(?!$)"), "")<<"\n";
}


int32_t main()
{

    int n,wmax=0,temp;
    cin>>n;
    vector<pair<int,int>>vec;
    int w[n+2],s[n+2],v[n+2],w1[n+2],v1[n+2],s1[n+2];
    for (int i = 1; i <= n; ++i)
    {
        cin>>w1[i]>>s1[i]>>v1[i];
        vec.push_back(make_pair(s1[i]+w1[i],i));
        wmax=max(wmax,w1[i]+s1[i]);
    }
    sort(vec.begin(),vec.end());
    for (int i = 1; i <= n; ++i)
    {
        temp=vec[i-1].second;
        //cout<<temp<<endl;
        w[i]=w1[temp];
        v[i]=v1[temp];
        s[i]=s1[temp];
    }
    int dp[n+2][wmax+2];
    memset(dp,0,sizeof(dp));
    //cout<<v[1]<<v[2]<<v[3]<<endl;
    for (int i = 1; i <= wmax; ++i)
    {
        if(i>=w[1])
            dp[1][i]=v[1];
        else
            dp[1][i]=0;
        //cout<<dp[1][i]<<" ";
    }
    //cout<<endl;
    //cout<<wmax<<endl;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0]=0;
        for (int j = 1; j <= wmax; ++j)
        {
            //if(i==3)
                //cout<<dp[i-1][j]<<endl;
            dp[i][j]=dp[i-1][j];
            if(j-w[i]>=0 && j-w[i]<=s[i])
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else if(j-w[i]<0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][s[i]]+v[i]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    //cout<<dp[2][6]<<endl;
    cout<<dp[n][wmax]<<endl;
}

