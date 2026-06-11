#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,p[200020],q[200020];

int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(p[i]);
		q[p[i]] = i;
	}
	int l = 0,lp = 1000009;
	int ans = n;
	for(int i=1;i<=n;i++){
		if(q[i]<lp){
			l = i;
		}
		lp = q[i];
		ans = min(ans,n-(i+1-l));
	}
	cout<<ans<<endl;
	return 0;
}
