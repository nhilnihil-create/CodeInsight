#include<bits/stdc++.h>
#define I64 "%I64d"
#define RAN(v)v.begin(),v.end()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
template<class T>
inline void upd1(T&a,T b){a>b?a=b:0;}
template<class T>
inline void upd2(T&a,T b){a<b?a=b:0;}
struct ano{
	operator ll(){
		ll x=0,y=0,c=getchar();
		while(c<48)
			y=c==45,c=getchar();
		while(c>47)
			x=x*10+c-48,c=getchar();
		return y?-x:x;
	}
}buf;
const int N=2e5+5;
char a[N];
int b[N];
bitset<1<<26>g;
map<int,int>f;
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	g[0]=1;
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]^1<<a[i]-97;
		if(!g[b[i]]){
			g[b[i]]=1;
			f[b[i]]=n;
		}
		for(int j=0;j<26;++j)
			if(g[b[i]^1<<j])
				upd1(f[b[i]],f[b[i]^1<<j]+1);
	}
	printf("%d\n",b[n]?f[b[n]]:1);
}