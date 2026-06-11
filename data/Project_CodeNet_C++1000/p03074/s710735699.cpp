#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    ll T=1,t,n,m,q,k,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>n>>k;
        string s;
        cin>>s;
        vector<pair<ll,ll>> rng;
        rng.pb(mp(0,0));
        FOR(i,0,s.length())
        {
            if(s[i]=='1') 
            {
                j=i;
                while (s[j]=='1') 
                    j++;
                rng.pb(mp(i,j));
                i = j-1;
            }
        } 
        rng.pb(mp(s.length(),s.length()));
        // for(auto it:rng)
        //     cout<<it.f<<" "<<it.s<<endl;   
        ll ans=0;
        FOR(i,0,rng.size())
        {
            j = min(i+k,(ll)rng.size()-1);
            ll len = rng[j].s - rng[i].f;
            ans = max(ans,len);
        }
        cout<<ans<<endl;
    }
}