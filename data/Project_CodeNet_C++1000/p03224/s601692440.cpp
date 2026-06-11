#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
vector<int> v[1000];
int dq;
int main(){
	int n=read();
	for(int i=1;i*(i-1)/2<=n;i++){
		if(i*(i-1)/2==n){
			for(int j=1;j<=i;j++){
				for(int k=j+1;k<=i;k++){
					v[j].push_back(++dq); v[k].push_back(dq);
				}
			}
			puts("Yes");
			cout<<i<<endl;
			for(int j=1;j<=i;j++){
				wri(v[j].size()); for(auto k:v[j])wri(k); puts("");
			}
			return 0;
		}
	}
	puts("No");
}
/*
f[i][j]->f[i+1][j]
f[i][j]->f[i+1][i]
*/