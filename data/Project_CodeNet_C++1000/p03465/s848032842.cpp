
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2000;
int a[maxn+5],n,now;
int num[maxn*maxn+5],T;
bitset<maxn*maxn+maxn> S;
int main(){
	scanf("%d",&n),S[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&now);
		S|=S<<now;
	}
	for(int i=1;i<=maxn*maxn;i++) if(S[i]) num[++T]=i;
	printf("%d\n",num[(T+1)>>1]);
	return 0;
}