#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;
int d[26];
int a[100];
int main()
{
	int n;scanf("%d",&n);++d[0];
	for(int i=0;i<n;++i){
		int t;
		scanf("%d",&t);
		++d[t];
		a[i]=t;
	}
	sort(a,a+n);
	for(int i=0;i<12;++i){
		if(d[i]>2||d[12]>1){
			printf("0");
			return 0;
		}
	}
	int ans=0;
	for(int bi=0;bi<(1<<n);++bi){
		mem(d,0);
		for(int i=0;i<n;++i){
			if((1<<i)&bi)++d[24-a[i]];
			else ++d[a[i]];
		}
		int dis=24,pre=0;
		for(int i=0;i<=24;++i){
			if(d[i]>1){dis=0;break;}
			else if(d[i]){dis=min(dis,i-pre);pre=i;}
		}
		dis=min(dis,24-pre);
		ans=max(ans,dis);
	}
	printf("%d",ans);

    return 0;
}
