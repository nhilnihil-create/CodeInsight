#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	vector<LL> l,r;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		l.push_back(x);
		r.push_back(y);
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());

	LL ans = 0;
	LL curr=0;

	for(int i=0;i<n;i++){
		curr+=(2*l[n-i-1]);
		ans = max(ans,curr);
		if((2*i + 1)>=n){break;}
		curr-=(2*r[i]);
		ans = max(ans,curr);
	}

	curr=0;
	for(int i=0;i<n;i++){
		curr-=(2*r[i]);
		ans = max(ans,curr);
		if((2*i + 1)>=n){break;}
		curr+=(2*l[n-i-1]);
		ans = max(ans,curr);
	}
	cout<<ans<<endl;
}