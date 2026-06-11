#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;
cs int N = 2e5 + 50;
int n, a[N], k, sta[N], vl[N], top, ok;
void ins(int x){
	if(!x) return ok=true, void();
	while(top&&sta[top]>x) --top;
	if(sta[top]==x){
		++vl[top]; 
		if(vl[top]>=k) vl[top]=0, --top, ins(x-1);
	} else sta[++top]=x, vl[top]=1;
}
bool chk(){
	ok=top=0; for(int i=1; i<=n; i++)
	if(a[i]<=a[i-1]) ins(a[i]);
	return !ok;
}
int main(){
	#ifdef FSYolanda
	freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n); int c=0;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]), c+=a[i]<=a[i-1];
	if(!c) return puts("1"),0;
	int l=2, r=n; while(l<r){
		int mid=(l+r)>>1; k=mid;
		if(chk()) r=mid; else l=mid+1;
	} cout<<l; return 0;
} 