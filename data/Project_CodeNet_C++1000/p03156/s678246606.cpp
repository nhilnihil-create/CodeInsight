#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
	int n,x,a,b,c,d,e;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x<=a)c++;
		else if(x>=a+1&&x<=b)d++;
		else if(x>=b+1)e++;
	}
	int ans=min(c,d);
	cout<<min(ans,e);
return 0;
}
