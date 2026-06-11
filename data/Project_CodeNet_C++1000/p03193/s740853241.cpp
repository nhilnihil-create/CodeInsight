#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int n;
	cin>>n;
	int h,w;
	cin>>h>>w;
	vector<int>a(n),b(n);
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}	
	int cnt=0;
	for(int i=0; i<n; i++){
		if(a[i]>=h&&b[i]>=w){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

signed main(){
	//while(1)
	solve();
}