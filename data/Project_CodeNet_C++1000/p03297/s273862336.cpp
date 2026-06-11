#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define for1(a,b,i) for(int i=a;i<=b;++i)
#define FOR2(a,b,i) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
inline int read() {
	int f=1,sum=0;
	char x=getchar();
	for(;(x<'0'||x>'9');x=getchar()) if(x=='-') f=-1;
	for(;x>='0'&&x<='9';x=getchar()) sum=sum*10+x-'0';
	return f*sum;
}

ll A,B,C,D;

inline ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}

int main() {
	//freopen("a.in","r",stdin);
	int Test_=read();
	while (Test_--) {
		cin>>A>>B>>C>>D;
		if(A<B||D<B) puts("No");
		else if(C>=B-1) puts("Yes");
		else {
			ll d=gcd(D%B,B)%B;
			if(!d) {
				if(A%B>=C+1) puts("No");
				else puts("Yes");			
			}
			else {
				if(A%B>=C+1) puts("No");
				else {
					ll c=C-A%B;
					c=c/d+1;
					if((c*d%B+A%B)%B>=C+1) puts("No");
					else puts("Yes");
				}
			}
		}
	}
}