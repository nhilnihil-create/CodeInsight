#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> v(n),c(n);
	for (int i=0; i<n; i++)
		cin>>v[i];
	for (int i=0; i<n; i++)
		cin>>c[i];
	int ret=0;
	for (int i=0; i<n; i++)
		ret+=max(0,v[i]-c[i]);
	cout<<ret<<endl;	
	return 0;
}
