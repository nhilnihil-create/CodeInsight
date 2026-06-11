#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,k,t=0;
	cin>>a>>b>>k;
	int d=0;
	for(int i=1;i<=10000;i++)
	{
		if(a%i==0&&b%i==0)
			ans[d++]=i;

	}
	cout<<ans[d-k];
	return 0;
}
