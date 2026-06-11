#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a,b;
int main(){
	a=read();b=read();
	if(a+b==15)cout<<"+";
	else
	if(a*b==15)cout<<"*";
	else
	cout<<"x";
	return 0;
}