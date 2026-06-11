#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll int rev(ll int n)
{
	int ans=0,r;
	while(n>0)
	{
		r=n%10;
		ans=(ans*10)+r;
		n/=10;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll int a,b,cnt=0;
	cin >> a >> b;
	for(ll int i=a;i<=b;i++)
	{
		//cout << rev(i) << endl;
		if((i-rev(i))==0) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}
