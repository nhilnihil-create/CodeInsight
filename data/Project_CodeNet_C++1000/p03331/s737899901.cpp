#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
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
    string s;
    cin>>s;
    int n=s.length();
    int sum=0;
    for(auto c:s)
        sum+=c-'0';
    if(s[0]=='1')
    {
        bool flag=true;
        for(int i=1;i<n;i++)
            if(s[i]!='0')
                flag=false;
            if(flag)
                cout<<10<<endl;
            else
                cout<<sum<<endl;
    }
    else
    cout<<sum<<endl;
}