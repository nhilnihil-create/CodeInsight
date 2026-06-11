#include<cstdio>
#define fo(x,a,b) for(int x=(a),e_=(b);x<=e_;x++)

const int N=200005;
int a[N],n;
struct node{int l,r,c;node(int u=0,int v=0,int w=0){l=u,r=v,c=w;}}s[N];

bool ck(int col){
	int top,len=a[1];
	s[top=1]=node(1,a[1],1);
	fo(i,2,n) {
		if(a[i]>len) {
			s[++top]=node(len+1,a[i],1);
			len=a[i];
			continue;
		}
		while(top>0 && s[top].r>a[i]) {
			if(s[top].l>a[i]) top--;
			else {s[top].r=a[i]; break;}
		}len=a[i];

		for(; top>0 && s[top].c==col; top--) ;
		if(top==0) return false;
		if(s[top].l<s[top].r) {
			++top;s[top].l=s[top].r=s[top-1].r;
			s[top].c=s[top-1].c+1;s[top-1].r--;
		} else s[top].c++;
		if(s[top].r+1<=len) top++,s[top]=node(s[top-1].r+1,len,1);
//		fo(j,1,top) printf("%d~%d:%d  ;",s[j].l,s[j].r,s[j].c);puts("");
	}return true;
}
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);

	int l=1, r=n, mid, ans=n;
	while(l<=r){
		mid=(l+r)>>1;
//		printf("mid:%d\n",mid);
		if(ck(mid)) r=mid-1, ans=mid; else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
