#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int m,a[N],b[N],ans[N];
void update(int v,int p){
	if(v>a[p]){
		b[p]=a[p];
		a[p]=v;
	}
	else if(v>b[p])b[p]=v;
}
int main(){
	scanf("%d",&m);
	int n=1<<m;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			int x=(1<<i);
			if(!(j&x)){
				update(a[j],j|x);
				update(b[j],j|x);
			}
		}
	for(int i=0;i<n;i++){
		ans[i]=a[i]+b[i];
		if(i!=0){
			ans[i]=max(ans[i],ans[i-1]);
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}