#include<bits/stdc++.h>
#define LL long long
#define RG register
#define R RG int
using namespace std;
const int N=1009;
int x[N],y[N];
int main(){
	ios::sync_with_stdio(0);
	R n,i,k,mx=0,L,cnt=1;RG bool tp;
	cin>>n;
	for(i=1;i<=n;++i)cin>>x[i]>>y[i],mx=max(mx,max(abs(x[i]),abs(y[i])));
	tp=(x[1]+y[1])&1;
	for(i=2;i<=n;++i)
		if(((x[i]+y[i])&1)!=tp)return cout<<"-1\n",0;
	for(L=1;L<=mx;L<<=1)++cnt;
	cout<<cnt+!tp<<endl;
	for(k=L;k;k>>=1)cout<<k<<' ';
	cout<<(tp?"":"1")<<endl;
	for(i=1;i<=n;++i){
		for(k=L;k;k>>=1){
			if(abs(x[i])>abs(y[i]))
				if(x[i]>0)x[i]-=k,cout<<'R';
				else      x[i]+=k,cout<<'L';
			else
				if(y[i]>0)y[i]-=k,cout<<'U';
				else      y[i]+=k,cout<<'D';
		}
		if(!tp){
			k=1;
			if(abs(x[i])>abs(y[i]))
				if(x[i]>0)x[i]-=k,cout<<'R';
				else      x[i]+=k,cout<<'L';
			else
				if(y[i]>0)y[i]-=k,cout<<'U';
				else      y[i]+=k,cout<<'D';
		}
		cout<<endl;
	}
	return 0;
}
