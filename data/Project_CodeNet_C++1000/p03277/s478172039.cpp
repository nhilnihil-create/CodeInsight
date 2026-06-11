#include<bits/stdc++.h>
using namespace std;
#define maxn 100020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef pair<int,int> pr;

int a[maxn],n,s[maxn],cnt[maxn * 2],tmp = 1e5 + 5;
ll num;

inline void modify(int x,int d){
	for (register int i = x ; i <= n + tmp ; i += lowbit(i)) cnt[i] += d;
}
inline int query(int x){
	int res = 0;
	for (register int i = x ; i ; i -= lowbit(i)) res += cnt[i];
	return res;
}
inline ll cal(int mid){
	rep(i,1,n) s[i] = s[i - 1] + ((a[i] <= mid) ? 1 : -1);
	rep(i,1,n + tmp) cnt[i] = 0;
	ll res = 0;
	rep(i,1,n){
		modify(s[i - 1] + tmp,1);
		res += query(s[i] + tmp - 1);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int l = 1 , r = 1e9 , ans = 0;
	num = (ll)n * (n + 1) / 4 + 1;
	while ( l <= r ){
		int mid = (l + r) >> 1;
		if ( cal(mid) >= num ) ans = mid , r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n",ans);
}
