#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> cnt(m+1);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			cnt[x]++;
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
		if(cnt[i]==n)ans++;
	cout<<ans;

}