#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int d; cin>>d;
	if (d==25) cout<<"Christmas"<<endl;
	else if (d==24) cout<<"Christmas Eve"<<endl;
	else if (d==23) cout<<"Christmas Eve Eve"<<endl;
	else if (d==22) cout<<"Christmas Eve Eve Eve"<<endl;
	else cout<<endl;
	return 0;
}
