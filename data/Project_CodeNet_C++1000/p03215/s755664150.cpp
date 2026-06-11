#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<char,char> p2;
#define sz(a) ll(a.size())
ll n,k,a[1005],res;
vector<ll> v;
void func(ll bit){
	if(!bit){
		cout<<res;
		exit(0);
	}
	vector<ll> temp;
	ll val=pow(2,bit-1);
	for(ll i=0;i<sz(v);i++){
		if(!(v[i]&val))
		continue;
		temp.push_back(v[i]);
	}
	if(sz(temp)>=k){
		res+=val;
		v=temp;
	}
	func(bit-1);
}
void solve(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll j=i;j<=n;j++){
			sum+=a[j];
			v.push_back(sum);
		}
	}
	func(50);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
    solve();
}
