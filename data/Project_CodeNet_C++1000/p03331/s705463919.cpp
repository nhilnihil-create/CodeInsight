#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=1e9;
int dig(int x){
	int res=0;
	while(x>0)
		res+=x%10,x/=10;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int a;
	cin>>n;
	for(a=1;a<n;a++)
		ans=min(ans,dig(a)+dig(n-a));
	cout<<ans;
	return 0;
}