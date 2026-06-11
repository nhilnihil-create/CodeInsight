#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a==1 && b==1 && c==1)
	{
		cout<<"1"<<endl;
	}
	else
	{
	vector<int>v;
	int f = min(a,b);
	for(int i=1;i<=f;i++)
	{
		if((a%i)==0 && (b%i)==0)
		{
			v.push_back(i);
		}
	}
	sort(v.rbegin(),v.rend());
	cout<<v[c-1]<<endl;
	}
	return 0;
}