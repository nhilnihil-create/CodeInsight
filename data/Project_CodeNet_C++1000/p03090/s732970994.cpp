#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b)
{
	return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
	a-=b;
	if(a<0){
		a+=mod;
	}
	return a;
}
 
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1){
			res=mul(res,a);
		}
		b/=2;
		a=mul(a,a);
	}
	return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}
 
const int N=1000002;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>groups;
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			groups.pb({i+1,n-i});
		}
	}
	else{
		for(int i=0;i<n/2;i++){
			groups.pb({i+1,n-i-1});
		}
		groups.pb({n,-1});
	}
	vector<pair<int,int>>ans;
	for(int i=0;i<groups.size();i++){
		for(int j=i+1;j<groups.size();j++){
			ans.pb({groups[i].F,groups[j].F});
			if(groups[j].S!=-1){
				ans.pb({groups[i].F,groups[j].S});
			}
			if(groups[i].S!=-1){
				ans.pb({groups[i].S,groups[j].F});
				if(groups[j].S!=-1){
					ans.pb({groups[i].S,groups[j].S});
				}
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans){
		cout<<i.F<<' '<<i.S<<"\n";
	}
			
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
