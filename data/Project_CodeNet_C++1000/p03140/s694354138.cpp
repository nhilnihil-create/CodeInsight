#include<bits/stdc++.h> 
#define ll                 long long                            
#define ra                 return a;                                          
#define pb                 push_back                                                     
#define sti                stack<ll>
#define spi                stack<pair<ll,ll>>
#define S                  second
#define msi                map<string,ll >
#define msi                map<string,ll >
#define mii                map<ll ,ll >
#define dbg(x)             { cerr<<#x<<": "<<x<< endl; }
#define dbg2(x,y)          { cerr<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl; }
#define dbg3(x,y,z)        { cerr<<#x<<": "<<x<<" , "<<#y<<": "<<y<<" , "<<#z<<": "<<z<<endl; }
#define mis                map<ll , string>
#define rep(i,a,b)         for(ll  i=a;i<b;i++)
#define mpi                map<pair<ll ,ll >,ll >                                                
#define pii                pair<ll ,ll >
#define ppb                pop_back
#define F                  first 
#define vi                 vector<ll >
#define vii                vector<pair<ll , ll >>
#define si                 set <ll>
#define vs                 vector<string>
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (ll )x.size()
#define hell               1000000007
#define bs                 binary_search
#define mp                 make_pair
#define qi                 queue<ll>
#define qs                 queue<string>
#define qpi                queue<pair<ll,ll>>
#define qps                queue<pair<ll,string>> 
#define endl               '\n' 
#define itr(a,it)          for(typeof(a.begin()) it=a.begin();it!=a.end();it++)// This will produce const_iterator for const object and normal iterator for non-const object
#define ss                 set<string>
using namespace std;
#define N  100005
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
//    cin>>t;
    while(t--)
{
    ll n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    rep(i,0,n)
    {
    	if(a[i]!=b[i])
    	{
    		if(a[i]!=c[i])
    		{
    			if(b[i]!=c[i])ans+=2;
    			else ans++;
    		}
    		else ans++;
    	}
    	else 
    	{
    		if(a[i]!=c[i])ans++;
    	}
    }
    cout<<ans;
}	
    return 0;
}