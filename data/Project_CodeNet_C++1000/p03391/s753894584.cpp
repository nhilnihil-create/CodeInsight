#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+7;
ll a[MAXN],b[MAXN],n,sum,minn=1e9+7;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		if(a[i]>b[i]) if(minn>b[i]) minn=b[i];
	}
	if(minn==1e9+7) cout<<0<<endl;
	else cout<<sum-minn;
}