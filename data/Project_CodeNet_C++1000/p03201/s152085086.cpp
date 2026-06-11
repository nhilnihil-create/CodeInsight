#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define int ll
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=200010;
int n,a[N],tot,t[N],ans;
multiset<int>se;
signed main(){
	n=gi();for(int i=1;i<=n;i++){
		a[i]=gi();se.insert(a[i]);
	}
	for(ll i=1;i<=2e9;i<<=1ll)t[++tot]=i;
	while(!se.empty()){
		int x=*se.rbegin();se.erase(se.find(x));
		for(int j=1;j<=tot;j++)
			if(x<t[j] && se.find(t[j]-x)!=se.end()){se.erase(se.find(t[j]-x)),ans++;break;}
	}
	printf("%lld\n",ans);
	return 0;
}
