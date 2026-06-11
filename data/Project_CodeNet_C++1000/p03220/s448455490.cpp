/**
*    author:  yuya1234
*    created: 24.06.2020 16:13:01
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,t,a;
    cin>>n>>t>>a;

    double h[1000];
    int ans = 0;
    REP(i,n)
    {
        cin>>h[i];
        h[i]=abs(a - (t-h[i]*0.006));
        if(h[i] < h[ans])ans=i;
    }

    cout<<ans+1<<endl;
    
    return 0;
}