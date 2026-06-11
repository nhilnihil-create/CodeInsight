#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define y1 itstakioi
const int N=2e5+10;

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int h,w,n,sr,sc;
char s[N],t[N];

void No() {
	cout<<"NO";exit(0);
}

int main() {
	cin>>h>>w>>n>>sr>>sc;
	scanf("%s%s",s+1,t+1);
	int now=sr;
	for(int i=1;i<=n;i++) {
		if(s[i]=='U') { --now;if(now<1) No(); }
		if(t[i]=='D') { if(now<h) ++now; }
	}
	now=sr;
	for(int i=1;i<=n;i++) {
		if(s[i]=='D') { ++now;if(now>h) No(); }
		if(t[i]=='U') { if(now>1) --now; }
	}
	now=sc;
	for(int i=1;i<=n;i++) {
		if(s[i]=='L') { --now;if(now<1) No(); }
		if(t[i]=='R') { if(now<w) ++now; }
	}
	now=sc;
	for(int i=1;i<=n;i++) {
		if(s[i]=='R') { ++now;if(now>w) No(); }
		if(t[i]=='L') { if(now>1) --now; }
	}
	cout<<"YES";
	return 0;
}
