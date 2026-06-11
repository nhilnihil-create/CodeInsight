#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int main(){
	int q=read();
	while(q--){
		int a=read(),b=read();
		if(a>b)swap(a,b);
		ll pro=(ll)a*b-1;
		int l=0,r=b-1;
		while(l<r){
			int mid=(l+r)>>1; mid++;
			//cout<<(long double)pro/mid-(long double)pro/(mid+1)<<endl;
			if(pro<(ll)mid*(mid+1))r=mid-1; else l=mid;
		}
		writeln(a-1+l+max((ll)0,pro/(l+1)-a));
	}
}
/*
8
1 4
10 5
3 3
4 11
8 9
22 40
8 36
314159265 358979323
pro*(mid+1)-pro*mid<mid*(mid+1)
1
1 4
*/