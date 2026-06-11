//problem:agc029_c
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a[200005];
bool check(int mid){
	map<int,int>mp;
	for(int i=1;i<=n;++i){
		if(a[i]<=a[i-1]){
			if(mid==1)return 0;
			while(mp.size()&&mp.rbegin()->fst>a[i]){
				map<int,int>::iterator it=mp.end();
				mp.erase(--it);
			}
			for(int j=a[i];j>=0;--j){
				if(!j)return 0;
				mp[j]++;
				if(mp[j]==mid)mp[j]=0;
				else break;
			}
		}
	}
	return 1;
}
int main() {
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	int l=1,r=n;while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}