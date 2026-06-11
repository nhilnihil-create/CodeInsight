#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n;
int main()
{
	cin >> n;
	int x=0,y=0,l=0;
	for(int i=0,t,a,b; i<n; i++)
	{
		cin >> t >> a >> b;
		int k=abs(x-a)+abs(y-b);
		if(t-l < k || (k-t+l)%2)
		{
			cout << "No";
			return 0;
		}
		x=a,y=b,l=t;
	}
	cout << "Yes";
	return 0;
}
