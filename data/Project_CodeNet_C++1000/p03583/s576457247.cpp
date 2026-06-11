#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int mx=3500;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll N; cin>>N;
	for (ll a=1; a<=mx; a++)
		for (ll b=1; b<=mx; b++) {
			ll p=N*a*b;
			ll q=4*a*b-N*(a+b);
			if(q<=0)
				continue;
			if(p%q)
				continue;
			ll c=p/q;
			if(c>mx)
				continue;
			cout<<a<<" "<<b<<" "<<c<<"\n";
			return 0;
		}
	return 0;
}