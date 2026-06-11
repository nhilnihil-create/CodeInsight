#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
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
#include<string>
string s;
int dp[1<<26],sum,oo=10000005;
int main(){
	cin>>s;
	for(int i=1;i<(1<<26);i++)dp[i]=oo;
	for(int i=0;i<s.length();i++){
		sum^=1<<(s[i]-'a');
		int zs=oo;
		for(int j=0;j<26;j++)zs=min(zs,dp[sum^(1<<j)]+1);
		if(i==s.length()-1)cout<<min(dp[sum]+1,zs)<<endl;
		dp[sum]=min(dp[sum],zs);
	}
}