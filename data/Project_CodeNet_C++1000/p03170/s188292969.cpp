#include <bits/stdc++.h>
using namespace std;

#define Art Code
#define Artist Shivam Gupta
#define MoT This Art belongs to Artist
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vl(p) vector<p>
#define W while
#define For(i,s,x) for(i=s;i<x;i++)
#define Fore(i,s,x) for(i=s;i<=x;i++)
#define FoR(i,s,x) for(i=s-1;i>=x;i--)
#define ForE(i,s,x) for(i=s;i>=x;i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define in insert
#define sz size()
#define F first
#define S second
#define nl cout<<"\n"
#define pr(a) cout<<a<<" "
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define pr3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define MAX 200005

int main() {
    FASTIO;
    ll t=1, i, j, k, l;
    // cin>>t;
    W(t--) {
        ll n, m;
        cin>>n>>k;
        ll a[n+1];
        Fore(i,1,n) cin>>a[i];
        ll dp[k+1]={};
        // Fore(i,a[1],a[n]) dp[i]=1;
        Fore(i,0,k)
            Fore(j,1,n)
                if(i-a[j]>=0&&dp[i-a[j]]==0) dp[i]=1;
        if(dp[k]) pr("First");
        else pr("Second");  
    }
    return 0;
}