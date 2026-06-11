#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N,M; cin>>N>>M;
	vector<int> X(N),Y(N),Z(N);
	for(int i=0;i<N;i++)cin>>X[i]>>Y[i]>>Z[i];
	int ans=0;
	for(int bit=0;bit<8;bit++){
		vector<int> tmp(N);
		for(int i=0;i<N;i++){
			if(bit & (1<<0))tmp[i]+=X[i];
			else tmp[i]-=X[i];
			if(bit & (1<<1))tmp[i]+=Y[i];
			else tmp[i]-=Y[i];
			if(bit & (1<<2))tmp[i]+=Z[i];
			else tmp[i]-=Z[i];
		}
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		int a=0;
		for(int i=0;i<M;i++)a+=tmp[i];
		a=abs(a);
		ans=max(a,ans);
	}
	cout<<ans<<endl;
}