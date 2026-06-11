#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int l;

int main(){
	l=read();
	int n=(int)(log(l)*1.0/log(2))+1;
	cout<<n<<' '<<2*(n-1)+__builtin_popcount(l)-1<<endl;
	for(int i=1;i<n;i++){
		cout<<i<<' '<<i+1<<' '<<0<<endl;
		cout<<i<<' '<<i+1<<' '<<(1<<(i-1))<<endl;
	}
	int nw=(1<<(n-1));
	for(int i=n-2;i>=0;i--){
		if(l&(1<<i)){
			cout<<i+1<<' '<<n<<' '<<nw<<endl;
			nw=nw+(1<<i);
		}
	}
	return 0;
}
