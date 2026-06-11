#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n,lt;
	cin>>n>>lt;
	
	int nw=1001;
	int ans=0;
	for(int i=0;i<n;i++){
		int c,t;
		cin>>c>>t;
		
		if(t<=lt) if(c<nw) nw=c;
	}
	if(nw>=1001) cout<<"TLE"<<endl;
	else cout<<nw<<endl;
	return 0;
}