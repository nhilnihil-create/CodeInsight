#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define nmax 100005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n;
int a[nmax];

bool solve(int p){
	vector<int> pre(n+1,0);
	ordered_set st;
	ll ans=0;
	st.insert(0);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+((a[i]<=p)?1:-1);
		ans+=st.order_of_key(pre[i]);
		st.insert(pre[i]);
		if(ans>(1ll*n*(n+1))/4){
			return 1;
		}
	}
	return ans>(1ll*n*(n+1))/4;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	vector<int> b(a+1,a+n+1);
	sort(b.begin(),b.end());
	
	int l=-1, r=b.size()-1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(solve(b[mid])){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	
	cout << b[r] << endl;
	return 0;
}