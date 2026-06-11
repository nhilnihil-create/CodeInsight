#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
int a[Maxn+5];
int n;
int pos[Maxn+5],num[Maxn+5],len;
bool check(int x){
	len=0;
	num[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			continue;
		}
		if(len==0){
			pos[++len]=a[i];
			num[len]=1;
			continue;
		}
		while(len>0&&pos[len]>a[i]){
			len--;
		}
		if(len>0&&pos[len]==a[i]){
			num[len]++;
			while(len>0&&num[len]==x){
				int now=pos[len]-1;
				len--;
				if(pos[len]==now){
					num[len]++;
				}
				else{
					pos[++len]=now;
					num[len]=1;
				}
			}
		}
		else{
			pos[++len]=a[i];
			num[len]=1;
		}
		if(num[0]>0){
			return 0;
		}
	}
	return 1;
}
int main(){
	read(n);
	bool one=1;
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]<=a[i-1]){
			one=0;
		}
	}
	if(one){
		puts("1");
		return 0;
	}
	int left=2,right=n,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
	return 0;
}
