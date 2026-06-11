#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define rsi resize
 
#define er(x) cerr<<#x<<": "<<x<<" "<<endl
#define er2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define er3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define er4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define erar(a) {cerr<<#a<<" "; for(auto x : a) cerr<<x<<" "; cerr<<endl;}
 
#define int long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define mii map< int,int >
 
#define rep(i,a,b) for(i=a; i<b; i++)
#define repr(i,a,b) for(i=a; i>b; i--)
#define put(a,b) cout<<a<<b
#define sz(a) (int)a.size()
#define all(v) v.begin(),v.end()

 
struct node { double x,y; };
 
#define inf 100000000000000
#define M 1000000007
 
int n,m,k;


void solve()
{
    int i,j,x,y,z;
    string s;
    cin>>s;
    
    vi a;
    
    n = sz(s);
    int ct = 0;
    int ans = 0;
    
    rep(i,0,n-1)
    {
        if ( s[i] == 'B' && s[i+1] == 'C' )
        {
            a.pb(ct);
            i++;
            ct = 0;
            continue;
        }
        
        if ( s[i] == 'A' ) ct++;
        else
        {
            ct = 0;
            rep(j,0, sz(a) )
                ans += (sz(a)-j)*a[j];
            a.clear();
        }
    }
    
    rep(j,0, sz(a) )
                ans += (sz(a)-j)*a[j];
    
    put(ans,'\n');

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    
    // cin>>t; 
    
    while(t--) solve();
}