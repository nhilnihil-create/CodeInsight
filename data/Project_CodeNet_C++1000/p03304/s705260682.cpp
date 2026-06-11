#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,d; cin>>n>>m>>d;
	double ret=(m-1.)/n;
	if(d) ret=2.*(n-d)/n/n * (m-1);
	cout<<setprecision(10)<<fixed<<ret<<"\n";
	return 0;
}