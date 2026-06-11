#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define MN 500005
int n;
pii a[MN];
int main(){
	int N,M;read(N);read(M);read(n);
	for(int i=1;i<=n;++i){
		read(a[i].ft);read(a[i].sd);
	}
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=1;i<=n;++i){
		if(a[i].ft-a[i].sd>mx)return printf("%d",a[i].ft-1),0;
		if(a[i].ft-a[i].sd==mx)++mx;
	}
	cout<<N;
	return 0;
}
