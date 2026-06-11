#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    int n,m;
    cin>>n>>m;
    string s;
    string t;
    cin>>s>>t;
    int ans=gcd(n,m);
    ans=(n*m)/ans;
    map<int,int>o;
    int cnt=0;
    for(int i=0;i<=(n-1)*(ans/n);i+=(ans/n))
    {
        o[i]=s[cnt++];
    }
    cnt=0;
    for(int i=0;i<=(m-1)*(ans/m);i+=(ans/m))
    {
        if(o.count(i))
        {
            if(o[i]!=t[cnt])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}