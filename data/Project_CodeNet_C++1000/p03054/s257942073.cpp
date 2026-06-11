#include <cstdio>
#define Maxn 200000
char s[Maxn+5],t[Maxn+5];
int n;
int h,w,sx,sy;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d%d",&h,&w,&n);
	scanf("%d%d",&sx,&sy);
	scanf("%s",t+1);
	scanf("%s",s+1);
	int f=1,e=h;
	for(int i=n;i>0;i--){
		if(s[i]!='L'&&s[i]!='R'){
			if(s[i]=='U'){
				e=mn(e+1,h);
			}
			else{
				f=mx(f-1,1);
			}
		}
		if(t[i]!='L'&&t[i]!='R'){
			if(t[i]=='U'){
				f++;
			}
			else{
				e--;
			}
		}
		if(f>e){
			puts("NO");
			return 0;
		}
	}
	if(sx<f||sx>e){
		puts("NO");
		return 0;
	}
	f=1,e=w;
	for(int i=n;i>0;i--){
		if(s[i]!='U'&&s[i]!='D'){
			if(s[i]=='L'){
				e=mn(e+1,w);
			}
			else{
				f=mx(f-1,1);
			}
		}
		if(t[i]!='U'&&t[i]!='D'){
			if(t[i]=='L'){
				f++;
			}
			else{
				e--;
			}
		}
		if(f>e){
			puts("NO");
			return 0;
		}
	}
	if(sy<f||sy>e){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
