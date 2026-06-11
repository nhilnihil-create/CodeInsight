#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
	ll n,i,j,p,k,m,ans=0;
    cin>>n>>m;
    vector<ll> a(n);
    ll b,c;
    vector<pair<ll,ll> > v;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    
    for(i=0;i<m;i++)
    {
        cin>>b>>c;
        v.pb({c,b});
    }
    
    sort(a.begin(),a.end());
    sort(v.begin(),v.end(),greater<pair<ll,ll>>());
    j=0;
    for(i=0;i<m;i++)
    {
        b=v[i].S;
        c=v[i].F;
        ll tmp=0;
        while(tmp<b && a[j]<c)
        {
            a[j]=c;
            tmp++;j++;
            if(j==n)
            break;
        }
        if(j==n)
        break;
    }
    
    ans=0;
    for(i=0;i<n;i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;

	return 0;
}