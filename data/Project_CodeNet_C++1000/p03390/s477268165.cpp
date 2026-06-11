#include <bits/stdc++.h> 
using namespace std;
long long n,m,i,j,ans,x,y,l,r,mid;
int main(){
	cin>>n;
	while (n--){
		cin>>x>>y;
		if (x==1&&y==1){
			cout<<"0\n";
			continue;
		}
		if (x==y||abs(x-y)==1){
			cout<<(min(x,y)-1)*2<<endl;
			continue;
		}
		ans=0;l=0;r=0x3fffffff;
		while (l<r){
			mid=(l+r)/2;
			if (mid*mid<x*y){
				ans=mid;
				l=mid+1;
			}
			else r=mid;
		}
		//cerr<<ans<<endl;
		if (ans*(ans+1)>=x*y){
			cout<<ans*2-2<<endl;
			continue;
		}
		cout<<ans*2-1<<endl;
	}
	return 0;
}