#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,a,b;
int ans[500005];

int main(void){
	scanf("%d%d%d",&n,&a,&b);
	int cur=n;
	int pos=0;
	int mxa=0;
	for(int i=0;i<b;i++){
		int us=min(a,cur-(b-i-1));
		if(us<=0){
			printf("-1\n");
			return 0;
		}
		if(i==0 && us!=a){
			printf("-1\n");
			return 0;
		}
		for(int j=0;j<us;j++){
			ans[pos++]=cur-us+j+1;
		}
		cur-=us;
		if(cur<=-1){
			printf("-1\n");
			return 0;
		}
	}
	if(pos<n){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		printf("%d%c",ans[i],i+1==n?'\n':' ');
	}
	return 0;
}
