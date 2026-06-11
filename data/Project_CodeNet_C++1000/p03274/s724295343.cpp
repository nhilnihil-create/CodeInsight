#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n,k;	
	cin>>n>>k;	
	vector<ll>x(n);
	ll tmp=0;	
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	ll ans=1145141919;
	for(int i=0,j=i+k-1;j<n;i++,j++){
		ans=min(ans,x[j]-x[i]+min(abs(x[i]),abs(x[j])));
	}
	cout<<ans<<endl;
	return 0;
}
