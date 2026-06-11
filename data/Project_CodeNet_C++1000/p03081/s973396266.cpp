#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
char t[200000];
char d[200000];
int main()
{
	string s;
	int n,q;
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<q;i++)
		cin>>t[i]>>d[i];
	int l;//左に落ちる最も右側
	int r;//右に落ちる最も左側
	//左を調べる
	int ok=-1;
	int ng=n;
	while(ng-ok>1)
	{
		int mid=(ok+ng)/2;
		int now=mid;//midのゴーレムが落ちることができるか調べる
		for(int i=0;i<q;i++)
		{
			if(now==-1 || now==n)
				break;
			if(t[i]==s[now])
			{
				if(d[i]=='L')
					now--;
				else
					now++;
			}
		}
		if(now==-1)
			ok=mid;
		else
			ng=mid;
	}
	l=ok;
	//右を調べる
	ok=n;
	ng=-1;
	while(ok-ng>1)
	{
		int mid=(ok+ng)/2;
		int now=mid;//midのゴーレムが落ちることができるか調べる
		for(int i=0;i<q;i++)
		{
			if(now==-1 || now==n)
				break;
			if(t[i]==s[now])
			{
				if(d[i]=='L')
					now--;
				else
					now++;
			}
		}
		if(now==n)
			ok=mid;
		else
			ng=mid;
	}
	r=ok;
	cerr<<l<<" "<<r<<endl;
	cout<<r-l-1<<endl;
	return 0;
}