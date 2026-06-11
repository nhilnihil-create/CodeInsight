#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
const int N=1e5+10;
void solve()
{
    VL visit(N,0);
    for(int i=2;i*i<=N;i++)
    {
        if(visit[i]==0)
        {
            for(int j=i;j<=N;j+=i)
            {
                visit[j]=1;
            }
            visit[i]=2;
        }

    
    }
    fr(i,2,N)
    {
        if(visit[i]==0)
            visit[i]=2;
    }
    VL pref(N,0);

    fr(i,2,N)
    {
        if(visit[i]==2)
        {
            if(visit[(i+1)/2]==2)
            {
                pref[i]=1;
            }
        }
    }
    fr(i,1,N)
    {
        pref[i]+=pref[i-1];
    }
    ll q;
    cin>>q;
    fr(i,0,q)
    {
        ll l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
    return;
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm