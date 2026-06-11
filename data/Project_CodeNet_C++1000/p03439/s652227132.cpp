#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int exc(string s)
{
	if(s=="Vacant") return 0;
	if(s=="Male")return 1;
	if(s=="Female")return 2;
	return -1;
}
int main()
{
	int N;
	cin>>N;
	vector<int> table(N,-1);
	cout<<0<<endl;
	string s;
	cin>>s;
	table[0]=exc(s);
	if(table[0]==0)return 0;
	cout<<N-1<<endl;
	cin>>s;
	table[N-1]=exc(s);
	if(table[N-1]==0)return 0;
	int head=0;
	int tail=N-1;
	rep(cnt,18)
	{
		int mid=(head+tail)/2;
		if(table[mid]!=-1)
		{
			if(head>=N/2)
			{
				head=0;
				tail=(N-1)/2;
			}
			else
			{
				head=(N-1)/2;
				tail=N-1;
			}
		}
		cout<<mid<<endl;
		cin>>s;
		table[mid]=exc(s);
		if(table[mid]==0) break;
		if(((mid-head)%2==0&&table[head]==table[mid])||((mid-head)%2==1&&table[head]!=table[mid]))
		{
			head=mid;
		}
		else
		{
			tail=mid;
		}
	}
	return 0;
}
