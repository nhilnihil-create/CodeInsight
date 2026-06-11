#include<bits/stdc++.h>
const int MAXN=10000;
const int INF=400000;
using namespace std;

map<long long, int> pos;

void mainp()
{
	string s;
	cin>>s;
	
	pos[0]=0;
	long long num=0ll;
	int temp=INF;
	for(int i=s.size()-1; i>=0; i--)
	{
		num^=(1<<(s[i]-'a'));
		temp=INF;
		for(int j=0; j<26; j++)
		{
			num^=(1<<j);
			if(pos.count(num)) temp=min(temp, pos[num]);
			num^=(1<<j);
		}
		if(pos.count(num)) temp=min(temp, pos[num]);
		
		if(!pos.count(num)) pos[num]=temp+1;
		else if(pos[num]>temp+1) pos[num]=temp+1;
	}
	
	cout<<temp+1<<endl;
}
int main()
{
	mainp();
	return 0;
}
