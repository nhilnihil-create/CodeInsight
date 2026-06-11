#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double d;

ll ar[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0;i<6;i++)
	{
		ll a;cin>>a;
		ar[a]++;
	}	
	for(int i=1;i<=4;i++)
		if(ar[i]>=3)
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";	
	return 0;
}