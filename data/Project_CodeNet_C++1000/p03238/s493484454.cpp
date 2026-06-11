// Debug : debug template
// Number : number theory 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pi pair<int,int>
#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

typedef tree<int,null_type, /*greater<int>,*/
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// find_by_order() and order_of_key() returns pointers
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

void solve(){
	// your main solution for each testcase
	int type;
	cin >> type;
	if(type==1){
		cout << "Hello World\n";
	}
	else{
		int a,b;
		cin >> a >> b;
		cout << a+b << "\n";
	}
}

int main(){
	IOS;
	int test=1;
	// cin >> test;
	while(test--)
		solve();

	return 0;
}
