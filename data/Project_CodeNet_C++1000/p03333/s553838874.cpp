#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
typedef long double LD;
typedef pair <int,int> pii;
typedef pair <int,LL> piL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=100005;
int n;
int L[N],R[N];
int idL[N],idR[N];
int del[N];
int p;
LL ans;
bool cmpL(int a,int b){
	return L[a]>L[b];
}
bool cmpR(int a,int b){
	return R[a]<R[b];
}
void Go(int x){
	if (L[x]<=p&&p<=R[x])
		return;
	if (p>R[x])
		ans+=p-R[x],p=R[x];
	else
		ans+=L[x]-p,p=L[x];
}
LL calc(int k){
	ans=p=0;
	clr(del);
	int lp=1,rp=1;
	For(i,1,n){
		if ((i&1)==k)
			del[idR[rp]]=1,Go(idR[rp]);
		else
			del[idL[lp]]=1,Go(idL[lp]);
		while (del[idL[lp]])
			lp++;
		while (del[idR[rp]])
			rp++;
	}
	ans+=abs(p);
	return ans;
}
int main(){
	n=read();
	For(i,1,n)
		L[i]=read(),R[i]=read();
	For(i,1,n)
		idL[i]=idR[i]=i;
	sort(idL+1,idL+n+1,cmpL);
	sort(idR+1,idR+n+1,cmpR);
	cout<<max(calc(0),calc(1))<<endl;
	return 0;
}