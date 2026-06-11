#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int maxn=2e5+7;
int st[maxn],num[maxn];
int main()
{
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0,L=1,R=n;
	auto check=[&](int x){
		int top=0;
		num[0]=0;
		int pre=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>pre)
			{
				pre=a[i];
				continue;
			}
			if(!top)
			{
				st[++top]=a[i];
				num[top]=1;
			}
			else{
				if(x==1) return false;
				while(top&&st[top]>a[i]) top--;
				if(top&&st[top]==a[i])
				{
					++num[top];
					while(top&&num[top]==x)
					{
						int nxt=st[top]-1;
						top--;
						if(st[top]==nxt) ++num[top];
						else st[++top]=nxt,num[top]=1;
					}
				}
				else{
					st[++top]=a[i],num[top]=1;
				}
			}
			//dbg(x,i,top,st[top],num[top]);
			pre=a[i];
		}
		return num[0]==0;
	};
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))
		{
			R=mid-1;
			ans=mid;
		}
		else L=mid+1;
	}
	print(ans);
}
