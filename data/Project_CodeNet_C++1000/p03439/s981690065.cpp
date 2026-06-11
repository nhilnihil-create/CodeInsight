#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	int n;
	cin >> n;
	cout<<0<<endl;
	string zero;
	cin >> zero;
	int l = 0,r=n;
	string uke;
	string de;
	while(1)
	{
		int m = (l+r)/2;
		cout<<m<<endl;
		cin >> uke;
		if(r-l<2)
		{
			break;
		}
		if(uke=="Vacant")return 0;
		else if((m%2==0)?(zero!=uke):(zero==uke))
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return 0;
}