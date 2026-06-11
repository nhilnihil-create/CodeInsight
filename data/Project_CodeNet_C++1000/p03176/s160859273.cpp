#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);
ll int mpw(ll int a,ll int b,ll int m)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
 
ll int pw(ll int a,ll int b)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
 
ll int mn(ll int a,ll int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}
 
ll int mx(ll int a,ll int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}
int sz;
vector<ll int>seg;
ll int query(int l,int r)
{
	l+=sz-1;
	r+=sz-1;
	ll int ans=0;
	while(l<r && l>=0)
	{
		if((l&1)==0)
		{
			ans=mx(ans,seg[l]);
			l++;
		}
		if(r&1)
		{
			ans=mx(ans,seg[r]);
			r--;
		}
		l=(l-1)/2;
		r=(r-1)/2;
	}
	if(l==r && l>=0)
	{
		ans=mx(ans,seg[l]);		
	}
	return ans;

}
void upd(int indx,ll int val)
{
	int p=sz-1+indx;
	seg[p]=val;
	while(p>0)
	{
		int tmp=(p-1)/2;
		seg[tmp]=mx(seg[2*tmp+1],seg[2*tmp+2]);
		p=tmp;
	}
	seg[p]=mx(seg[2*p+1],seg[2*p+2]);
	return;
}

int main()
{
	fio
	int n;
	cin>>n;
	sz=pow(2,ceil(log2(n)));
	seg.clear();
	seg.resize(2*sz,0);
	vector<pair<int,int>>h(n);
	vector<ll int>pr(n);
	for(int i=0;i<n;++i)
	{
		cin>>h[i].first;
		h[i].second=i;
	}
	for(int i=0;i<n;++i)
	{
		cin>>pr[i];
	}
	sort(h.begin(),h.end());
	ll int ans=0;
	for(int i=0;i<n;++i)
	{
		pair<int,int>p=h[i];
		ll int tmp=query(0,p.second)+pr[p.second];
		ans=mx(ans,tmp);
		upd(p.second,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}