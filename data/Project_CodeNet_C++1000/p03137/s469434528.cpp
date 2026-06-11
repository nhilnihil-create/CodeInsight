#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n,m; cin>>n>>m;
	vector<int> v(m);
	rep(i,m) cin>>v[i];
	sort(all(v));
	m--;
	vector<int> d(m);
	rep(i,m) d[i]=v[i+1]-v[i];
	sort(all(d));
	if(n>=m+1) cout<<0<<endl;
	else{
		n--;
		ll ans=accumulate(d.begin(),d.end()-n,0);
		cout<<ans<<endl;
	}
}