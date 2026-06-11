#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int H,W; cin>>H>>W;
	int c[10][10];
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			cin>>c[i][j];
	ll dist[10][10]{INT_MAX};
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
				dist[i][j]=c[i][j];
	for (int k=0; k<10; k++)
		for (int i=0; i<10; i++)
			for (int j=0; j<10; j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	int ret=0;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			int x; cin>>x;
			if(x==-1) continue;
			ret+=dist[x][1];
		}
	}
	cout<<ret<<"\n";
	return 0;
}