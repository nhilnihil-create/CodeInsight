#include<bits/stdc++.h>
using namespace std;
#define lg long long
int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		lg x,y;
		cin>>x>>y;
		lg t=sqrt(x*y-1);
		if(t*t>=x*y) t--;
		lg res=t*2;
		if(t*(t+1)>=(x*y))--res;
		if(t>=x)--res;
		if(t>=y)--res;
		cout<<res<<'\n';
	}
	return 0;
}