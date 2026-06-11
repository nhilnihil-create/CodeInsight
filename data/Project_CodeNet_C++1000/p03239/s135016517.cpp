#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin>>n; cin>>t;
	int res=1001;
	for (int i=0; i<n; i++){
		int c, tx;
		cin>>c; cin>>tx;
		if (tx<=t&&c<res)
			res=c;
	}
	if (res==1001) cout<<"TLE"<<endl;
	else cout<<res;
	return 0;
}