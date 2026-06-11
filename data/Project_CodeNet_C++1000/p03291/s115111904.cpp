#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<long long, long long>
#define f first
#define s second
#define debug cout<<"here\n" 
#define MOD 1000000007
 
using namespace std;

ll modexp(ll a, ll p, ll mod){
	if(p == 0) return 1;
	ll ans = modexp(a,p/2,mod);
	ans = (ans*ans)%mod;
	if(p%2) return (ans*a)%mod;
	else return ans;
}

void solve(){	
	int n; 
	string s; cin>>s;
	n = s.length();
	ll x=0,y=0,z=0,xx,yy,zz,k=0;
	for(int i=0; i<n; i++){
		if(s[i] == '?'){
			k++;
			xx = (3*x + modexp(3,k-1,MOD))%MOD;	
			yy = (3*y + x)%MOD;
			zz = (3*z + y)%MOD;
			x = xx; y = yy; z = zz;
		}
		else if(s[i] == 'A') x = (x+modexp(3,k,MOD))%MOD;
		else if(s[i] == 'B') y = (x+y)%MOD;
		else z = (z+y)%MOD;
	}
	cout<<z;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);	
	cout<<fixed<<setprecision(12);

	int t =1; //cin>>t;
	for(int i=1; i<= t; i++){
		solve();
		cout<<"\n";
	}
	
	return 0;
}