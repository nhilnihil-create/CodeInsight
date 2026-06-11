#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define rvc(i,S) for(int i=0;i<(int)S.size();++i)
#define fore(i,x) for(int i = head[x] ; i ; i = e[i].next)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define lowbit(x) (x&(-x))
using namespace std;
#define maxn 200020

typedef long long ll;
typedef long double ld;

ll A,B,C,D;
int T;

ll gcd(ll x,ll y){
	if ( !y ) return x;
	return gcd(y,x % y);
}
int main(){
	cin>>T;
	while ( T-- ){
		cin>>A>>B>>C>>D;
		if ( A < B || D < B ){ printf("No\n"); continue; }
		ll d = gcd(B,D);
		A = A % B;
		ll L = floor((ld)(C - A) / d) + 1 , R = ceil((ld)(B - A) / d) - 1;
		if ( L <= R )  printf("No\n");
		else  printf("Yes\n");
	}
}
