//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

struct S
{
    int w,s,v;
    
    bool operator<(const S &b) const
    {
        return w+s < b.w+b.s;
    }
};
signed main()
{
    fast;
    int n;
    cin >> n;
    vector<S> ip(n);
    vector<int> dp(2e4+1,0);
    for(int i=0;i<n;i++)
    {
        cin >> ip[i].w >> ip[i].s >> ip[i].v;
    }
    sort( ip.begin() , ip.end() );
    for( auto p : ip )
    {
        for( int W = p.s ; W >= 0 ; W-- )
            dp[ W+p.w ] = max( dp[ W+p.w ] , dp[W] + p.v );
    }
    cout << *max_element( dp.begin() , dp.end() );
        
}



