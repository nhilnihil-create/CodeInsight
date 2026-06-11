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
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=200005;
int n;
vector <int> v;
int f[N];
int main(){
	n=read();
	if (n==3)
		return puts("2 5 63"),0;
	For(i,1,30000)
		f[i]=i%2==0||i%3==0||i%5==0;
	For(i,1,29970)
		if (f[i])
			v.pb(i);
	while (1){
		random_shuffle(v.begin()+3,v.end());
		int sum=0;
		For(i,0,n-2)
			sum+=v[i];
		sum=30000-sum%30;
		if (f[sum]){
			For(i,0,n-2)
				printf("%d ",v[i]);
			printf("%d\n",sum);
			return 0;
		}
	}
	return 0;
}