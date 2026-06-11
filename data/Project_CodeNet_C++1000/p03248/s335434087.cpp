#include"bits/stdc++.h"
using namespace std;
int main()
{
	string s;
	cin>>s;
	bool ok=1;
	int n=s.length();
	ok&=s[n-1]!='1';
	ok&=s[0]=='1';

	for(int i=1;i<n-1;i++)
		ok&=(s[i]==s[n-i-2]);
	if(!ok){puts("-1");return 0;}


	vector<int> pos;
	for(int i=0;i<n;i++)if(s[i]=='1')pos.push_back(i+1);

	int k=pos.size();
	
	//body
	for(int i=1;i<=k;i++)cout<<i<<" "<<i+1<<"\n";


	int cur=k+2;
	for(int i=2;i<=k;i++)
	{
		int prn=pos[i-1]-pos[i-2]-1;

		for(int j=0;j<prn;j++)
		cout<<i<<" "<<(cur++)<<"\n";
	}
}
