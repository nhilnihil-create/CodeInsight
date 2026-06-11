#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
string s;
int tong[3],mmax,mmin;
int main(){
	cin>>s;
	for(int i=0;i<s.length();i++)tong[s[i]-'a']++;
	mmax=max(tong[0],max(tong[1],tong[2]));
	mmin=min(tong[0],min(tong[1],tong[2]));
	if(mmax-mmin>1){
		puts("NO");
	}else puts("YES");
}