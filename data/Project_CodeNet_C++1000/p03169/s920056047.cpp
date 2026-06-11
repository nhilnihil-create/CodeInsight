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

ll N;
ld n, dp[301][301][301];

ld solve(ll x, ll y, ll z) {
    if(x<0||y<0||z<0) return 0;
    if(dp[x][y][z]>=0) return dp[x][y][z];
    // if(x&&y==0&&z==0) a=n/x+solve(x-1,y,z);
    // else if(x==0&&y&&z==0) a=n/y+solve(x+1,y-1,z);
    // else if(x==0&&y==0&&z) a=n/z+solve(x,y+1,z-1);
    // else {
    dp[x][y][z]=(x*solve(x-1,y,z)+y*solve(x+1,y-1,z)+z*solve(x,y+1,z-1)+n)/(x+y+z);
    return dp[x][y][z];
    
}


int main() {
    FASTIO;
    ll t=1, i, j, k, l;
    // cin>>t;
    W(t--) {
        cin>>N;
        n=N;
        ll a[N+1];
        ll x=0, y=0, z=0;
        Fore(i,1,N) {
            cin>>a[i];
            if(a[i]==1) x++;
            if(a[i]==2) y++;
            if(a[i]==3) z++;
        }
        Fore(i,0,300) Fore(j,0,300) Fore(k,0,300) dp[i][j][k]=-1;
        dp[0][0][0]=0;
        cout<<fixed<<setprecision(12)<<solve(x,y,z);
        nl;
    }
    return 0;
}