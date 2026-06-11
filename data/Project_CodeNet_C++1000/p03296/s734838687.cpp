#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	int ans=0;
	for(int i=1; i<n; i++){
		if(a[i]==a[i-1]){
			int cnt=2;
			i+=1;
			while(i<n&&a[i]==a[i-1]){
				i+=1;
				cnt+=1;
			}
			ans+=cnt/2;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	//while(1)
	solve();
}