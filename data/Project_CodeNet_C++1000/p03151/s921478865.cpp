#include <cstdio>
#include <queue>
using namespace std;
int n,a[100005],b[100005],ab[100005],ans; 
long long sumab,sums;
priority_queue<int>q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	for(int i=1;i<=n;++i){
		ab[i]=a[i]-b[i];
		sumab+=ab[i];
		if(ab[i]>0)q.push(ab[i]);
	}
	if(sumab<0)printf("-1\n");
	else{
		for(int i=1;i<=n;++i){
			if(ab[i]<0){
				++ans;
				while(sums+ab[i]<0){
					ab[i]+=sums;
					++ans;
					sums=q.top();
					q.pop();
				}
				sums+=ab[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
