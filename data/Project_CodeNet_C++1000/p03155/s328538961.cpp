#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h,w;
	cin>>n>>h>>w;
	int x=n+1-h;
	int y=n+1-w;
	int ans=x*y;
	cout<<ans<<endl;
	return 0;
}