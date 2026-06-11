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
	vector<int> a(N), b(N);
	ll cur=0,val=0;
	for (int i=0; i<N; i++)
		cin>>a[i], cur-=a[i];
	for (int i=0; i<N; i++)
		cin>>b[i], cur+=b[i];
	for (int i=0; i<N; i++)
		if(a[i]<b[i])
			cur-=(b[i]-a[i]+1)/2;
	cout<<((cur<0)?"No":"Yes")<<"\n";
	return 0;
}
