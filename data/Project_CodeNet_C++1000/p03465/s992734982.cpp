/*
 _____ _             _              _           _ 
|_   _| |__   ___   / \   _ __  ___| |__  _   _| |
  | | | '_ \ / _ \ / _ \ | '_ \/ __| '_ \| | | | |
  | | | | | |  __// ___ \| | | \__ \ | | | |_| | |
  |_| |_| |_|\___/_/   \_\_| |_|___/_| |_|\__,_|_|                                                

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define    endl        '\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
#define PI 3.141592653589793
#define N  2005
bitset<N*N> dp;


void solve()
{
    ll n;
    cin>>n;
    ll x,sum=0;
    dp[0]=1;
    rep(i,0,n)
    {
        cin>>x;
        dp= (dp<<x) | dp;
        sum+=x;
    }
    sum=(sum+1)/2;
    while(!dp[sum]) sum++;
    cout<<sum<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    time
    return 0;
}