#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int r; cin>>r;
	if (r<1200) cout<<"ABC"<<endl;	
	else if (r<2800) cout<<"ARC"<<endl;
	else cout<<"AGC"<<endl;
	return 0;
}
