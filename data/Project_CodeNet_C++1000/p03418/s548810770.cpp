#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	long long s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(i<=k) continue;
		s+=(i-k)*(n/i);
		s+=max(n%i-k+1,0);
	}
	if(k==0) s-=n;
	cout<<s;
}