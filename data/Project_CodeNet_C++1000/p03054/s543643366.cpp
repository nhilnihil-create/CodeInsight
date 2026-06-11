#include<bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
int h,w,n,sr,sc;
int walk1(){
	int l=1,r=h;
	for(int i=n;i>=1;i--){
		if(t[i]=='U')
			r=min(h,r+1);
		else if(t[i]=='D')
			l=max(l-1,1);
		if(s[i]=='U')
			l++;
		else if(s[i]=='D')
			r--;
		if(l>r)
			return 1;
	}
	return (sr<l||sr>r); 
}
int walk2(){
	int l=1,r=w;
	for(int i=n;i>=1;i--){
		if(t[i]=='L')
			r=min(w,r+1);
		else if(t[i]=='R')
			l=max(l-1,1);
		if(s[i]=='R')
			r--;
		else if(s[i]=='L')
			l++;
		if(l>r)
			return 1;
	}
	return (sc<l||sc>r); 
}
int main(){
	scanf("%d%d%d",&h,&w,&n);
	scanf("%d%d",&sr,&sc);
	scanf("%s",s+1);
	scanf("%s",t+1);
	if(walk1()||walk2())
		puts("NO");
	else puts("YES");
}