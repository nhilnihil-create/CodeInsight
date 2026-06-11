#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int h,w,n;
	cin >> h >> w >> n;
	int sr,sc;
	cin >> sr >> sc;
	sr--;
	sc--;
	string s,t;
	cin >> s >> t;

	int now = sc;
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='L')now--;
		if(now<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='R'&&now<w-1)now++;
	}
	now = sc;
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='R')now++;
		if(now>=w)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='L'&&now>0)now--;
	}
	now = sr;
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='D')now++;
		if(now>=h)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='U'&&now>0)now--;
	}
	now = sr;
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='U')now--;
		if(now<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='D'&&now<h-1)now++;
	}
	cout<<"YES"<<endl;
	return 0;
}
