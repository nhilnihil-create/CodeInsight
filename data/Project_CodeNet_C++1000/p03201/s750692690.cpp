#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int N=200005;

int n,t,ans;
int f[N],a[N];
map<int,int> cnt;

int main(){
	int i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	sort(a+1,a+1+n);
	for (i=n;i>=1;i--){
		if (!cnt[a[i]]) continue;
		cnt[a[i]]--;
		j=1;
		while(1ll*j*2<=1ll*(a[i]+a[i]))j=j*2;
		if (cnt[j-a[i]]){
			ans++;
			cnt[j-a[i]]--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
