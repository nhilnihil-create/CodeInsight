#include<iostream>
#include<algorithm>
#include<map>
typedef long long lint;
using namespace std;

int main()
{
	lint N,P;
	map<lint,lint> m;
	lint ans=1;
	lint num=0;
	
	cin >> N >> P;
	
	if(P==1)
	{
		cout << 1 << endl;
		return 0;
	}
	if(N==1)
	{
		cout << P << endl;
		return 0;
	}

	lint x=P;
	for(lint i=2;i*i<=P;i++)
	{
		while(x%i==0)
		{
			m[i]++;
			x/=i;
		}
	}
	
	for(auto it=m.rbegin();it!=m.rend();++it)
	{
		//cout << it->first << " " << it->second << endl;
		if(it->second>=N)
		{
			lint tmp=it->second/N;
			for(lint i=0;i<tmp;i++)ans*=it->first;
		}
	}
	cout << ans << endl;
	return 0;
}