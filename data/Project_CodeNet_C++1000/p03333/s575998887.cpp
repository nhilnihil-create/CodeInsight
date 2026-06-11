#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> L,R;
	long long int ans = 0;
	for(int i=1,l,r;i<=n;i++)
		cin>>l>>r,L.emplace_back(l),R.emplace_back(r);
	L.emplace_back(0);
	R.emplace_back(0);
	sort(L.rbegin(),L.rend());
	sort(R.begin(),R.end());
	long long int cur = 0;
	for(int i=0;i<L.size();i++)
		cur+=L[i]-R[i],ans=max(ans,cur);
	cout<<ans*2<<endl;
}
