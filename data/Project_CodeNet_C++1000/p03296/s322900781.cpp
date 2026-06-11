#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,a[100010];
int main() {
	read(n);
	int ans = 0,cnt = 0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=a[i-1])ans+=cnt/2,cnt = 1;
		else cnt++;
	}
	ans+=cnt/2;
	cout<<ans<<endl;
	return 0;
}
