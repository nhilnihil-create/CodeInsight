#include<bits/stdc++.h>
#define MAX 5002
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define Mod 1000000007
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n;cin>>n;
	// if(n==1 || n==2){
	// 	cout<<"No"<<endl;
	// 	return 0;
	// }

	bool triangular = 0;
	ll x = 0;
	For(i,1,n+1){
		x += i;
		if(x==n) {triangular = 1;x=i;break;}
	}

	if(!triangular){
		cout<<"No"<<endl;return 0;
	}
	x++;
	vector<ll> ans[x];
	ll c = 0;
	ll index = 0;
	ll next_index = 1;

	while(c<n){
		// cout<<index<<" "<<next_index<<endl;
		ans[index].pb(c);
		ans[next_index++].pb(c++);
		if(ans[index].size()==x-1) {
			index++;
			next_index=index+1;
			if(next_index>=x) next_index=0;
		}
	}

	cout<<"Yes"<<endl;
	cout<<x<<endl;
	For(i,0,x){
		cout<<ans[i].size()<<" ";
		For(j,0,ans[i].size()){
			cout<<ans[i][j]+1<<" ";
		}
		cout<<endl;
	}
}