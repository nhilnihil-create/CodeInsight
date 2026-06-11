#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

int m;
char s[50];

int main(){
	int n=read(),ans=0;
	poly cnt(3);
	For(i,1,n){
		scanf("%s",s+1),m=strlen(s+1);
		FOR(j,1,m) ans+=s[j]=='A'&&s[j+1]=='B';
		if (s[1]=='B'&&s[m]=='A') ++cnt[0];
		else if (s[1]=='B') ++cnt[1];
		else if (s[m]=='A') ++cnt[2];
	}
	if (cnt[0]){
		if (cnt[1]) --cnt[1],++ans;
		if (cnt[2]) --cnt[2],++ans;
		ans+=cnt[0]-1;
	}
	ans+=min(cnt[1],cnt[2]),printf("%d\n",ans);
}