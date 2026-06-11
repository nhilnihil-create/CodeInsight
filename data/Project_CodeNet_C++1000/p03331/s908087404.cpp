#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int func(int x)
{
	if(x<10)return x;
	else return x%10+func(x/10);
}

int main()
{
	int n,ans=1000000000;
	cin>>n;
	for(int i=1;i<=n/2;i++)
	{
		int a=i,b=n-i;
		ans=min(ans,func(a)+func(b));
	}
	cout<<ans<<endl;
	return 0;
}