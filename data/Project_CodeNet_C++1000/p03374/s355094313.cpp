#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,c;
int x[100100],v[100100];

int solve(){
	int prefix[n],suffix[n];
	for(int i=0;i<n;i++){
		if(i==0) prefix[0]=(v[0]-x[0]);
		else prefix[i]=(prefix[i-1]+v[i]-(x[i]-x[i-1]));
	}
	int maxi[n+1];
	maxi[n]=0;

	suffix[n-1]=(v[n-1]-2*(c-x[n-1]));
	maxi[n-1]=max((int)0,suffix[n-1]);
	for(int i=n-2;i>=0;i--){
		suffix[i]=(suffix[i+1]+v[i])-2*((c-x[i])-(c-x[i+1]));
		maxi[i]=max(maxi[i+1],suffix[i]);
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		int t = prefix[i]+maxi[i+1];
		ans = max(ans,t);
	}
	return ans;
}

signed main(){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>x[i]>>v[i];
	}
	int t1 = solve();
	for(int i=0;i<n;i++){
		x[i]=c-x[i];
	}
	reverse(x,x+n);
	reverse(v,v+n);
	int t2 = solve();
	cout<<max(t1,t2)<<endl;
}