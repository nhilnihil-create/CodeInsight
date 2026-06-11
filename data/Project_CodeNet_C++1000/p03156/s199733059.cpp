#include<bits/stdc++.h>
using namespace std;
#define ioS            ios::sync_with_stdio(false);cin.tie(0);
#define li             long int
#define ll            long li
#define ull            unsigned ll
#define pi             pair<int,int>
#define vi             vector<int>
#define vli            vector<li>
#define vll           vector<ll>
#define vvi            vector<vector<int>>
#define pb             push_back
#define mp             make_pair
#define forn(i,s,n)    for(auto i=s;i<n;++i)               
#define forr(i,s,n)    for(auto i=s;i>=n;--i) 
const ll MOD = 1e9+7;
const li mx = 1e6+1; 
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    vi p(n);
    forn(i,0,n)
        cin>>p[i];
    int prob[3]={0};
    forn(i,0,n)
        prob[(p[i]>a)+(p[i]>b)]++;
    cout<<min(prob[0],min(prob[1],prob[2]))<<endl;
}
int32_t main()
{
    ioS
    int t;
    // cin>>t;
    // while(t--)
        solve();
}
