#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int H,W,D; cin>>H>>W>>D;
	vector<pair<int,int>> fie(100000);
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int a; cin>>a;
			fie[a].first=i;
			fie[a].second=j;
		}
	}

	vector<int> dist(fie.size());
	dist[1]=0; dist[0]=0;
	for(int i=2;i<H*W+100;i++){
		if(i-D<0)dist[i]=0;
		else{
			dist[i]=dist[i-D]+llabs(fie[i].first-fie[i-D].first)+llabs(fie[i].second-fie[i-D].second);

		}

	}

	int Q; cin>>Q;
	for(int i=0;i<Q;i++){
		int L,R,ans=0;
		cin>>L>>R;
		ans=dist[R]-dist[L];
		cout<<ans<<endl;
	}
	return 0;
}