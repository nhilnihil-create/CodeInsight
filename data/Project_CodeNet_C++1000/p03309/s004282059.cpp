#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;

typedef vector <ll> vl;
typedef pair< ll, ll > pll;


int main()
{
    ll t,i,j,k,ans,n,sum;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        vl v(n+1);

        rep(p, 1, n+1) {
            cin>>v[p];
            v[p]-=p;
            //cout<<v[p]<<"\n";
        }
        sort(v.begin()+1,v.end());
        k = v[n/2 + 1],ans=0;
        //cout<<k<<"\n";
        rep(p, 1, n+1) {
            ans+=abs(v[p]-k);
            //cout<<abs(v[p]-k)<<"\n";
        }
        cout<<ans;
    }
    
    return 0;
}
