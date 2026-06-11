#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int to[N],n,x,cnt,ans;
map<int,int> Map;
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d",&x);
		if (!Map.count(x))to[++cnt]=x;
		Map[x]++;
	}
	sort(to+1,to+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
		for (int j=0;j<=30;j++)
			if ((1<<j)>to[i])while (Map[to[i]]>0&&Map[(1<<j)-to[i]]>0){
				if (to[i]*2==(1<<j)&&Map[to[i]]==1)break;
				Map[to[i]]--,Map[(1<<j)-to[i]]--,ans++;
			}
	printf("%d\n",ans);
}
