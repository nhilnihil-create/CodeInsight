#include<iostream>
#include<unordered_map>
using namespace std;
string s;
int d[200001];
unordered_map<int,int> best;
int main()
{
	cin>>s;
	int n=s.size(),x=0;s=' '+s;
	best[0]=0;
	for(int i=1;i<=n;i++)
	{
		d[i]=i;
		x^=1<<(s[i]-'a');
		for(int j=0;j<26;j++)
			if(best.count(x^(1<<j)))d[i]=min(d[i],best[x^(1<<j)]+1);
		if(best.count(x))d[i]=min(d[i],best[x]),best[x]=min(best[x],d[i]);
		else best[x]=d[i];
	}
	cout<<max(1,d[n])<<endl;
	return 0;
}
