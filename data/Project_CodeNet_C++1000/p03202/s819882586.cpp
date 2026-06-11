#include <bits/stdc++.h>
#define PB push_back
#define MP std::make_pair
#define FI first
#define SE second
#define M 1000005
#define INF 1000000000
int n,S[M],top;
bool flag=1;
std::pair <int,int> Stack[M];
int read(){
	char c=getchar();int ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}
void Write(int x){
	if (x<10) putchar(x+'0');
	else Write(x/10),putchar(x%10+'0');
	return;
}
void Insert(int x,int up){
	while (Stack[top].FI>x) top--;
	if (Stack[top].FI==x) Stack[top].SE++;
	else Stack[++top]=MP(x,1);
	if (Stack[top].SE==up){
		if (x==1) return flag=0,void();
		--top,Insert(x-1,up);
	}
	return;
}
bool check(int x){
	flag=1;top=0;
	for (int i=2;i<=n&&flag;i++)
		if (S[i]<=S[i-1]) Insert(S[i],x);
	return flag;
}
int main(){
	n=read();int ml=2,mr=n;
	for (int i=1;i<=n;i++) S[i]=read();
	for (int i=1;i<n;i++) flag&=(S[i]<S[i+1]);
	if (flag) return !printf("1");
	while (ml<=mr){
		int mid=(ml+mr)/2;
		if (check(mid)) mr=mid-1;
		else ml=mid+1;
	}
	return Write(ml),0;
}