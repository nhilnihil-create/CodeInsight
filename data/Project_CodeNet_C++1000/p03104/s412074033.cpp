#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

ll eval(ll n) {
	if(n<=0) return 0;
	ll ret=0;
	for (ll cur=ll(n/4)*4; cur<=n; cur++)
		ret^=cur;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll A,B; cin>>A>>B;
	cout<<(eval(B)^eval(A-1))<<"\n";
	return 0;
}