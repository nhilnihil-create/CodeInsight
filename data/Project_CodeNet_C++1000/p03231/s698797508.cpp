//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+5;
int n,m;
char s[MAXN],t[MAXN];
int main() {
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	ll L=(ll)n/__gcd(n,m)*m;
	int l1=L/n,l2=L/m;
	ll g=(ll)l1/__gcd(l1,l2)*l2;
	for(int i=0;(ll)i*(g/l1)+1<=n&&(ll)i*(g/l2)+1<=m;++i){
		if(s[i*(g/l1)+1]!=t[i*(g/l2)+1])return puts("-1"),0;
	}
	cout<<L<<endl;
	return 0;
}