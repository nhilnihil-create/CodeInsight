#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int maxn=1e6+10;
char s[maxn];
int main()
{
	int n,q;
	scanf("%d %s %d",&n,s+1,&q);
	while(q--){
		int k;
		scanf("%d",&k);
		ll ans=0,now=0;
		int cntd=0,cntm=0;
		for(int i=1;i<=n;i++){
			if(i>k){
				if(s[i-k]=='D'){
					cntd--;
					now-=cntm;
				}
				if(s[i-k]=='M'){
					cntm--;
				}
			}
			if(s[i]=='D'){
				cntd++;
			}
			if(s[i]=='M'){
				cntm++;
				now+=cntd;
			}
			if(s[i]=='C'){
				ans+=now;
			}
		}
		printf("%lld\n",ans);
	}
}