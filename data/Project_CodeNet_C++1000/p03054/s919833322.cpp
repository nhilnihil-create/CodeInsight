#include<bits/stdc++.h> 

const int maxn=2e5+7;
int n,m,L;
int sx,sy;
char a[maxn];
char b[maxn];
int main()
{
	scanf("%d%d%d%d%d%s%s",&n,&m,&L,&sx,&sy,a+1,b+1);
	{
		int s=1,t=n;
		for(int i=L;i;--i){
			if(b[i]=='U' || b[i]=='D'){
				if(b[i]=='U')
					t=std::min(t+1,n);
				else s=std::max(s-1,1);
			}
			if(a[i]=='U' || a[i]=='D'){
				if(a[i]=='U')++s;
				else --t;
			}
			if(s>t)return!puts("NO");
		}
		if(sx<s || t<sx)
			return!puts("NO");
	}{
		int s=1,t=m;
		for(int i=L;i;--i){
			if(b[i]=='L' || b[i]=='R'){
				if(b[i]=='L')t=std::min(t+1,m);
				else s=std::max(s-1,1);
			}
			if(a[i]=='L' || a[i]=='R'){
				if(a[i]=='L')++s;
				else --t;
			}
			if(s>t)return!puts("NO");
		}
		if(sy<s || t<sy)
			return!puts("NO");
	}puts("YES");
	return 0;
}