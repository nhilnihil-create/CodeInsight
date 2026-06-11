#include<bits/stdc++.h>
#define	MIN(a,b,c)	min(min(a,b),c)
#define	MAX(a,b,c)	max(max(a,b),c)
#define ll          long long
#define itr         vector<int>::iterator
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
using namespace std;
vector<ll> v;
void pri(ll n)
{
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        v.push_back(n);        
}
int main(){
	ll n,p;cin>>n>>p;
	pri(p);map<ll,ll> f;
	for(ll i=0;i<v.size();i++){
		f[v[i]]++;
	}
	ll ans=1;
	for(auto u:f){
		if(u.S>=n){
			ans=ans*pow(u.F,u.S/n);
		}
	}
	cout<<ans<<endl;
}
