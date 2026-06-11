/**
*    author:  yuya1234
*    created: 26.06.2020 11:45:39
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    ll a1,a2,a3;

    if(x>y)
    {
        a1=c*x*2;
        a2=c*y*2+a*(x-y);
    }
    else
    {
        a1=c*y*2;
        a2=c*x*2+b*(y-x);
    }
    a3=a*x+y*b;

    ll ans;
    ans=min(a1,a2);
    cout<<min(ans,a3)<<endl;
    

    return 0;
}