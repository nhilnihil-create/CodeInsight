#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
bool prime(int n){
	if(n<2) re 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) re 0;
	re 1;
}
vector<int> v;
signed main(){
	ios_base::sync_with_stdio(0);
	for(int i=3;i<1e5;i+=2)
		if(prime(i)&&prime((i+1)/2))
			v.pb(i);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<(upper_bound(all(v),r)-v.begin())-(lower_bound(all(v),l)-v.begin())<<"\n";
	}
	re 0;
}