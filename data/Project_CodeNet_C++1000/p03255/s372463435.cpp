#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=1e18;
int n,ts,tmp[500010],o,x[500010],X;
LL ans,t,s[500010];
int main(){
	cin>>n>>X;
	FOR(i,1,n) getint(x[i]),s[i]=s[i-1]+x[i];
	ans=INF;
	FOR(i,1,n){
		int cnt=0;
		t=0;
		for (int j=n;j>=1;j-=i){
			//j-i+1~j
			++cnt;
			o=max(j-i+1,1);
			t+=1ll*(cnt+1+cnt)*(s[j]-s[o-1]);
			if (j==n) t+=2ll*(s[j]-s[o-1]);
			t=min(t,INF);
		}
		/*
		t=0;
		FOR(j,0,i-1){
			ts=0;
			for (int k=j;k<=n;k+=i){
				if (k) tmp[++ts]=x[k];
			}
			t+=tmp[ts];
			FORD(k,ts,1){
				t+=1ll*(tmp[k]-tmp[k-1])*(ts-k+2)*(ts-k+2);
			}
		}
		*/
		t+=1ll*(i+n)*X;
		ans=min(ans,t);
	}
	cout<<ans<<endl;
    return 0;
}