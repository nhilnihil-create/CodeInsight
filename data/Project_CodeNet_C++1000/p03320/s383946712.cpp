#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){int w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}return w*s;}
inline int digit(ll a)
{
	ll res=0;while(a) res+=(a%10),a/=10;
	return res; 
}
inline bool cmp(ll a,ll b)
{
	if(a*digit(b)!=b*digit(a)) return a*digit(b)<b*digit(a);
	return a<b;
}
inline ll get(ll cur)
{
	vector<ll> ans;
	ll a=10,b=9;
	ll t=cur;
	ans.push_back(cur);
	while(t)
	{
		t/=10;
		ans.push_back(cur-cur%a+b);
		a*=10;
		b*=10;
		b+=9;
	}
	sort(ans.begin(),ans.end(),cmp);return ans[0];
}
int main()
{
	int k; 
	cin>>k;
	ll cur=0;
	while(k--)
	{
		cur=get(cur+1);
		cout<<cur<<"\n";
	}
	return 0;
}
