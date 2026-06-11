#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll h,w,n,x,y;
	cin >> h >> w >> n >> x >> y;
	string s,t;
	cin >> s >>t;
	ll xx = x,yy = y;
	for(int i = 0;i<n;i++)//高橋くんができるだけ右に寄せる
	{
		if(s[i]=='R')yy++;
		if(yy>w)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='L')yy--;
		yy = max(1LL,yy);
	}
	xx = x;
	yy = y;
	for(int i = 0;i<n;i++)//高橋くんができるだけ右に寄せる
	{
		if(s[i]=='L')yy--;
		if(yy==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='R')yy++;
		yy = min(w,yy);
	}
	xx = x;
	yy = y;
	for(int i = 0;i<n;i++)//高橋くんができるだけ右に寄せる
	{
		if(s[i]=='D')xx++;
		if(xx>h)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='U')xx--;
		xx = max(1LL,xx);
	}
	xx = x;
	yy = y;
	for(int i = 0;i<n;i++)//高橋くんができるだけ右に寄せる
	{
		if(s[i]=='U')xx--;
		if(xx==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(t[i]=='D')xx++;
		xx = min(h,xx);
	}
	cout<<"YES"<<endl;
}