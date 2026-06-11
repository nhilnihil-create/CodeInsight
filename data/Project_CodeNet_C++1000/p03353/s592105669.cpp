#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{	
	int k;
	string s;
	map<string,int>m;
	cin>>s>>k;
	for(int i=1;i<=5;i++)
	{
		if(s.length()<i)continue;
		for(int j=0;j<=s.length()-i;j++)
		{
			string t=s.substr(j,i);
			m[t]=1;
		}
	}
	auto itr=m.begin();
	itr=next(itr,k-1);
	cout<<itr->first<<endl;
	return 0;
}