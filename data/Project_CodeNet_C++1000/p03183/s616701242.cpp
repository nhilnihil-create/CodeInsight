#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);

//freopen("inp.txt",r,stdin);
//freopen("out.txt",w,stdout);
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

int main()
{
	fio
	int n;
	cin>>n;
	vector<pair<pair<int,int>,ll int>>nm(n);
	for(int i=0;i<n;++i)
	{
		cin>>nm[i].first.first>>nm[i].first.second>>nm[i].second;
	}
	sort(nm.begin(),nm.end(),[&](pair<pair<int,int>,ll int>l,pair<pair<int,int>,ll int>r)->bool{
		return l.first.first+l.first.second<r.first.first+r.first.second;
	});
	vector<ll int>D(22222,0);
	ll int ans=0;
	for(int i=0;i<n;++i)
	{
		vector<ll int>tmp=D;
		for(int j=0;j<=(nm[i].first.second);++j)
		{
			tmp[j+nm[i].first.first]=max(tmp[j+nm[i].first.first],D[j]+nm[i].second);
			ans=mx(ans,D[j]+nm[i].second);
		}
		D=tmp;
	}
	cout<<ans<<"\n";
	return 0;
}