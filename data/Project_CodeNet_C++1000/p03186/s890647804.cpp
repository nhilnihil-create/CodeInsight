#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
signed main(){
	int a=read(),b=read(),c=read();
	return cout<<min(a+b+1,c)+b,signed();
}