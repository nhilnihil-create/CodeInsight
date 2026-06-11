#include <bits/stdc++.h> 
using namespace std;
long long n,m,i,j,ans,x,y;
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
		ans=((long long)(sqrt(x*y)));
		if (ans*ans>=x*y) ans--; 
		if (ans*(ans+1)>=x*y){
			cout<<ans*2-2<<endl;
			continue;
		}
		cout<<ans*2-1<<endl;
	}
	return 0;
}