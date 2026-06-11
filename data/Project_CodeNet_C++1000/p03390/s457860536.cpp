#include<bits/stdc++.h>
using namespace std;
int main(){
	long long T,x,y;
	cin>>T;
	while(T--){
		cin>>x>>y;
		long long a=(sqrt(x*y));
		int ans=2*(int)(a)-1;
		if(a*a==x*y&&x!=y)--ans;
		if(a*(a+1)>=x*y)--ans;
		cout<<ans<<endl;
	}return 0;
}