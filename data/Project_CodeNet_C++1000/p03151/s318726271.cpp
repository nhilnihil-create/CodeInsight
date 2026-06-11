#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N; cin>>N;
	vector<int> A(N), B(N);
	for (int i=0; i<N; i++)
		cin>>A[i];
	for (int i=0; i<N; i++)
		cin>>B[i];
	int ret=0;
	ll cur=0;
	multiset<int> mst;
	for (int i=0; i<N; i++) {
		ll val=abs(A[i]-B[i]);
		if(A[i]<B[i]) cur+=val, ret++;
		else mst.insert(val);
	}
	while(!mst.empty()) {
		if(!cur) break;
		ll val=*mst.rbegin(); mst.erase(mst.find(val));
		cur-=min(cur,val); ret++;
	}
	cout<<(!cur?ret:-1)<<"\n";
	return 0;
}