#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#pragma GCC optimize(3)
using namespace std;
int n,a[10005],b[10005],s1,s2;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n*2;i++)
		(i>n)?(cin>>b[i-n]):(cin>>a[i]);
	for(int i=1;i<=n;i++)
		(a[i]>b[i])?(s1+=(a[i]-b[i])):(s2+=(b[i]-a[i])/2);
	cout<<(s1<=s2?"Yes\n":"No\n");
}

