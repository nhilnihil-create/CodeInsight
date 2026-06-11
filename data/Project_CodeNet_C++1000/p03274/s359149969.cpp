#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007
#define FOR(i,m,n) for(int i = (m); i < (n); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
 
 
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;

const int N=1e5+9;




int main(){
	
	fastio; 
	
	int n, k, x; cin>>n>>k;
	int pos=-1;
	vector<ll> v, d(n), ac1(n), ac2(n);
	bool p=1;
	FOR(i,0,n){
		cin>>x;
		if(x==0) p=0, k--, pos=i;
		if(x>0 && p) v.pb(0), pos=i, p=0;
		v.pb(x);
		if(p && x<0 && i==n-1) v.pb(0), pos=i+1, p=0;
	}
	ll ans=1e15;
	
	FOR(r,pos,pos+k+1){
		if(r>=k && r<sz(v)){
			ans=min(ans, 2*abs(v[r])+abs(v[r-k]));
			ans=min(ans, abs(v[r])+2*abs(v[r-k]));
		}
	}
	
	//FOR(i,0,sz(v)) cout<<v[i]<<" ";
	cout<<ans;
	
	return 0;
}
