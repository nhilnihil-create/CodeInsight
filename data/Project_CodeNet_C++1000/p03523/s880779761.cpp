#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}

string s,t="AKIHABARA",q="KIHBR";
bool ck(string a, string b){
	if(SZ(a)>SZ(b))return 0;
	for(int i=0,j=0;i<SZ(a);i++){
		while(j<SZ(b)&&a[i]!=b[j])j++;
		if(j>=SZ(b))return 0;j++;
	}
	return 1;
}
int main() {
	cin>>s;bool ok=ck(s,t)&&ck(q,s);
	printf("%s\n",ok?"YES":"NO");
	return 0;
}
