#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	for (int i=0; i<3; i++)
		if (s[i]=='1') cout<<"9";
		else if (s[i]=='9') cout<<"1";
		else cout<<s[i]<<endl;
	cout<<endl;	
	return 0;
}
