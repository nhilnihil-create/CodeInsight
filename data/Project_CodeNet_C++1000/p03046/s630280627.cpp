#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	if(k==0) {
		for(int i=0;i<(1<<n);i++) printf("%d %d ",i,i);
	}
	else if(n>1&&k<(1<<n)) {
		for(int i=(1<<n)-1;i>=0;i--) if(i!=k) printf("%d ",i);
		cout<<k<<' ';
		for(int i=0;i<(1<<n);i++) if(i!=k) printf("%d ",i);
		cout<<k<<endl;
	}
	else puts("-1");
}