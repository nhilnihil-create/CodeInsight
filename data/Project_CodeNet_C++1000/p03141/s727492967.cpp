#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,A,B; cin>>N;
	ll ret=0;
	vector<ll> X(N);
	for (int i=0; i<N; i++)
		cin>>A>>B, ret-=B, X[i]=A+B;
	sort(X.rbegin(),X.rend());
	for (int i=0; i<N; i+=2)
		ret+=X[i];
	cout<<ret<<"\n";
	return 0;
}