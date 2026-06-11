#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b? gcd(b,a%b):a;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,a[100001];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int lft[100001],right[100001];
	lft[0]=a[0];
	right[0]=a[n-1];
	for(int i=0;i<n-1;i++){
		lft[i+1]=gcd(lft[i],a[i+1]);
		right[i+1]=gcd(right[i],a[n-i-2]); 
	}
	//for(int i=0;i<n;i++)
	//cout<<lft[i]<<' '<<right[i]<<endl;
	int ans=1;
	for(int i=0;i<n;i++){
		int nowans;
		if(i==0)nowans=right[n-2-i];
		else if(i==n-1)nowans=lft[i-1];
		else nowans=gcd(lft[i-1],right[n-i-2]);
		ans=max(ans,nowans);
	}
	cout<<ans<<endl;
    return 0;
}
