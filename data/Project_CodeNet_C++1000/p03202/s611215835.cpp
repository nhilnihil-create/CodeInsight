#include<cstdio>
#include<algorithm>

void read_int (int &a) {
	char c=getchar(); a=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') a=(a<<1)+(a<<3)-48+c,c=getchar();
	return;
}

int n,a[200003];

int num[200003],pla[200003],tot,w;

bool inc (int lim) {
	if (pla[tot]!=w)
		++tot,pla[tot]=w,num[tot]=0;
	++num[tot];
	while (num[tot]==lim) {
		if (pla[tot]==1) return false;
		if (pla[tot-1]!=pla[tot]-1)
			--pla[tot],num[tot]=1;
		else --tot,++num[tot];
	} return true;
}

bool judge (int lim) {
	w=a[1]; tot=0;
	for (int now=2;now<=n;now++) {
		if (a[now]<w) while (pla[tot]>a[now]) --tot;
		else if (a[now]>w) { w=a[now]; continue; }
		w=a[now];
		if (!inc(lim)) return false;
	} return true;
}

int main () {
	
	read_int(n);
	for (int i=1;i<=n;i++)
		read_int(a[i]);
	
	int left=1,right=n,mid,ans;
	while (left<=right) {
		mid=left+right>>1;
		if (judge(mid)) ans=mid,right=mid-1;
		else left=mid+1;
	} printf("%d",ans);
	
	return 0;
}