#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll f(multiset<p2> s1,multiset<p2> s2,ll op){
	ll cur=0,res=0;
	while(!s1.empty()){
		p2 x;
		if(!op){
		    x=(*prev(s1.end(),1));
			s1.erase(prev(s1.end(),1));
			s2.erase(s2.find({x.second,x.first}));
			if(x.first<cur)
				break;
		}
		else{
			x=(*s2.begin());
			s1.erase(s1.find({x.second,x.first}));
			s2.erase(s2.begin());
			if(x.first>cur)
				break;
		}
		res+=abs(x.first-cur);
		cur=x.first;
		op^=1;
	}
	res+=abs(cur);
	return res;
}
void solve(){
	ll n;
	cin>>n;
	multiset<p2> s1,s2;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		s1.insert({x,y});
		s2.insert({y,x});
	}
	cout<<max(f(s1,s2,0),f(s1,s2,1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in01.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
        solve();
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}