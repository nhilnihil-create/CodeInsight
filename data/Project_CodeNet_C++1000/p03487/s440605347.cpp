#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vvl = vector<vector<ll>>;
using vl  = vector<ll>;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
const ll MOD = 1000000007;
const double PI = acos(-1);  
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||
//map<int,int>mp

ll n;
ll ans;
//string s,t;
signed main(){
	acc_io;
	cin>>n;
	map<int,int>a;
	rep(i,0,n){
		int tmp;
		cin>>tmp;
		++a[tmp];
	}
	ans=0;
	for(auto i:a){
//	for(pair<ll,ll> i:a){
		if(i.second>=i.first){
			ans+=i.second-i.first;
		}
		else{
			ans+=i.second;
		}
	}
	
//	DBG(s,t,0,0);
	cout<<ans<<endl;
	return 0;
}
