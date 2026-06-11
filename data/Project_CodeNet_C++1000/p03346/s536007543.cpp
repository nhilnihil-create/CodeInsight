#include<bits/stdc++.h>
using namespace std;


int p[200010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		p[x]=i;
	}
	int cur=0;
	for(int i=1;i<=n;i++){
		if(p[i]>p[i-1])	cur++;
		else	cur=1;
		ans=max(cur,ans);
	}
	cout<<n-ans<<endl;
}
