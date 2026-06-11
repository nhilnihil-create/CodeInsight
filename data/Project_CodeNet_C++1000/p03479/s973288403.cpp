#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main()
{	
	ll a,b,cnt=0;
	cin>>a>>b;
	while(a<=b/2)
	{
		a*=2;
		cnt++;
	}
	cout<<cnt+1<<endl;
	return 0;
}