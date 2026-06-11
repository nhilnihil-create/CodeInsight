#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll p[35];
void solve(){
	ll n,res=0;
	cin>>n;
	multiset<ll> m;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		m.insert(x);
	}
	while(!m.empty()){
		ll val=(*prev(m.end(),1));
		m.erase(prev(m.end(),1));
		if(m.empty())
		break;
		for(ll i=34;i>=0;i--)
		if(p[i]>val){
			auto it=m.find(p[i]-val);
			if(it==m.end())
			continue;
			m.erase(it);
			res++;
			break;
		}
	}
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p[0]=1;
    for(ll i=1;i<35;i++)
    p[i]=p[i-1]*2;
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
    solve();
}
