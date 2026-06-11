#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


pair<int,int> seg[800005];
int lz[800005];

void build(int ver,int tl,int tr)
{
	if(tl>tr)
		return ;
	else if(tl==tr)
	{
		lz[ver]=0;
		seg[ver]={0,tl};
	}
	else
	{
		int tm=(tl+tr)/2;
		build(2*ver,tl,tm);
		build(2*ver+1,tm+1,tr);
		seg[ver]=max(seg[2*ver],seg[2*ver+1]);
	}	
}

void push(int ver,int tm,int tr)
{
	lz[2*ver]=lz[ver];
	lz[2*ver+1]=lz[ver];
	seg[2*ver].first=0;
	seg[2*ver].second=tm;
	seg[2*ver+1].first=0;
	seg[2*ver+1].second=tr;
	lz[ver]=0;
}

void upd_pos(int ver,int tl,int tr,int pos,int val,int mid)
{
	if(tl>tr)
		return ;
	else if(tl==tr)
	{
		seg[ver].first+=val;
		if(seg[ver].first==mid)
			seg[ver].second=0;
	}
	else
	{
		int tm=(tl+tr)/2;
		if(lz[ver])
			push(ver,tm,tr);
		if(tm>=pos)
			upd_pos(2*ver,tl,tm,pos,val,mid);
		else
			upd_pos(2*ver+1,tm+1,tr,pos,val,mid);
		if(seg[2*ver+1].first<mid)
			seg[ver]=seg[2*ver+1];
		else
			seg[ver]=seg[2*ver];
	}	
}

void upd_lz(int ver,int tl,int tr,int l,int r,int mid)
{
	if(tl>tr||l>r||tr<l||r<tl)
		return ;
	else if(tl==l&&tr==r)
	{
		seg[ver].first=0;
		seg[ver].second=tr;
		lz[ver]=1;
	}	
	else
	{
		int tm=(tl+tr)/2;
		if(lz[ver])
			push(ver,tm,tr);
		upd_lz(2*ver,tl,tm,l,min(tm,r),mid);
		upd_lz(2*ver+1,tm+1,tr,max(tm+1,l),r,mid);
		if(seg[2*ver+1].first<mid)
			seg[ver]=seg[2*ver+1];
		else
			seg[ver]=seg[2*ver];
	}	
}

int get(int ver,int tl,int tr,int l,int r,int mid)
{
	if(tl>tr||l>r||tr<l||r<tl)
		return 0;
	else if(tl==l&&tr==r)
	{
		if(seg[ver].first==mid)
			return 0;			
		return seg[ver].second;
	}
	else
	{
		int tm=(tl+tr)/2;
		if(lz[ver])
			push(ver,tm,tr);

		if(seg[2*ver+1].first<mid)
			seg[ver]=seg[2*ver+1];
		else
			seg[ver]=seg[2*ver];
		return max(get(2*ver,tl,tm,l,min(tm,r),mid),get(2*ver+1,tm+1,tr,max(tm+1,l),r,mid));
	}	
}


signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
	if(fopen("INPUT.txt","r"))
	{
	freopen ("INPUT.txt" , "r" , stdin);
	freopen ("OUTPUT.txt" , "w" , stdout);
	}
#endif  

	int n;
	cin>>n;
	vector<int>temp;
	int a[n+1];
	a[0]=1e10;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
			continue;
		temp.push_back(a[i]);
	}

	set<int>s;
	map<int,int>mm;
	for(auto i:temp)
		s.insert(i);
	int cnt=0;
	for(auto i:s)
		mm[i]=++cnt;
	int sz=temp.size();
	// for(int i=0;i<sz;i++)
	// 	temp[i]=mm[temp[i]];
	
	int l=0,r=200000;
	int mn=2000000;
	// cout<<500<<'\n';
	// for(int i=1000;i>=2;i-=2)
	// {
	// 	cout<<i<<" ";		
	// }
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		int sz=temp.size();
		build(1,1,cnt);
		bool flag=true;
		for(int i=1;i<sz;i++)
		{
			int z=get(1,1,cnt,1,temp[i],mid);
			if(z==0)
			{
				flag=false;
				break;
			}
			upd_pos(1,1,cnt,z,1,mid);
			upd_lz(1,1,cnt,z+1,cnt,mid);
		}
		if(flag)
		{
			r=mid-1;
			mn=min(mn,mid+1);
		}
		else
		{
			l=mid+1;
		}		
	}

	cout<<mn;


}
