#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int32_t main()
{
    IOS
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    int x=__gcd(n,m);
    int N=n/x,M=m/x;
    for (int i=0;i<x;i++)
        if (s[N*i]!=t[M*i]) return cout<<-1<<endl,0;
    cout<<n*1ll*m/__gcd(n,m)<<endl;
}

