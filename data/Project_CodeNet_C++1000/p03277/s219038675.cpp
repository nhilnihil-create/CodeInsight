#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn],bit[maxn<<1];

inline void add(int x){
	while(x<maxn<<1){
		++bit[x];
		x+=x&-x;
	}
}
inline int sum(int x){
	int res=0;
	while(x){
		res+=bit[x];
		x-=x&-x;
	}
	return res;
}
inline bool check(int res){
	ll cnt=0;
	memset(bit,0,sizeof(bit));
	for(int i=1,t=maxn;i<=n;++i){
		add(t);
		t+=a[i]>=res?1:-1;
		cnt+=sum(t);
	}
	return cnt>=(n*(n+1ll)/2+1)/2;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int l=1,r=1e9;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}