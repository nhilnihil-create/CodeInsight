#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=37;
const int mo=998244353;

unsigned long long pw[maxn];
int n,len1,len2,a[maxn],b[maxn];
char s[maxn];

map<unsigned long long,int> mp[maxn];

void add(){
	unsigned long long hsh=0;
	for(int i=1;i<=len1;++i)
		hsh=(hsh+(s[a[i]]-'a'+3)*pw[i-1]);
	for(int i=1;i<=len2;++i)
		hsh=(hsh-(s[b[i]]-'a'+3)*pw[n-i]);
	++mp[len1][hsh];
}
ll res;
void query(){
	unsigned long long hsh=0;
	for(int i=1;i<=len1;++i)
		hsh=(hsh-(s[a[i]]-'a'+3)*pw[n-i]);
	for(int i=1;i<=len2;++i)
		hsh=(hsh+(s[b[i]]-'a'+3)*pw[i-1]);
//	for(int i=1;i<=len1;++i)printf("%c ",s[a[i]]);puts("");
//	for(int i=1;i<=len2;++i)printf("%c ",s[b[i]]);puts("");
//	printf("%d %d !\n",len1,hsh);
	res+=mp[n-len1][hsh];
}

void dfs1(int x){
	if(x>n){
		add();
		return ;
	}
	a[++len1]=x;
	dfs1(x+1);
	--len1;b[++len2]=x;
	dfs1(x+1);
	--len2;
}

void dfs2(int x){
	if(x<=n){
		query();
		return ;
	}
	a[++len1]=x;
	dfs2(x-1);
	--len1;b[++len2]=x;
	dfs2(x-1);
	--len2;
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	pw[0]=1;
	for(int i=1;i<=2*n;++i)
		pw[i]=pw[i-1]*233;
	dfs1(1);
	dfs2(2*n);
	printf("%lld\n",res);
	return 0;
}

