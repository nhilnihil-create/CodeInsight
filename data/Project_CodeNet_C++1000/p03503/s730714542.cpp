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
	vector<vector<int>> F(N,vector<int>(10,0));
	for (int i=0; i<N; i++)
		for (int j=0; j<10; j++)
			cin>>F[i][j];
	vector<vector<int>> P(N,vector<int>(11,0));
	for (int i=0; i<N; i++)
		for (int j=0; j<11; j++)
			cin>>P[i][j];
	int ans=INT_MIN;
	for (int bt=1; bt<(1<<10); bt++) {
		vector<int> ct(N,0);
		for (int i=0; i<10; i++)
			if(bt&(1<<i))
				for (int j=0; j<N; j++)
					ct[j]+=F[j][i];
		int ret=0;
		for (int i=0; i<N; i++)
			ret+=P[i][ct[i]];
		ans=max(ans,ret);
	}
	cout<<ans<<"\n";
	return 0;
}