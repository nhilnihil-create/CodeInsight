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

int n,l[100010],r[100010];
ll ans = 0;

ll calc(){
	sort(l,l+n);
	sort(r,r+n);
	int p1 = n-1,p2 = 0;
	int cp = 0;
	ll ans = 0;
	bool run =1;
	while(run){
		run = 0;
		if(p1>=0 && l[p1]>cp){
			ans+=l[p1]-cp;
			cp = l[p1];
			p1--;
			run = 1;
		}
		if(p2<n && r[p2]<cp){
			ans+=cp-r[p2];
			cp = r[p2];
			p2++;
			run = 1;
		}
	}
	ans+=abs(cp);
	return ans;
}

int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(l[i]);
		read(r[i]);
	}
	ans = calc();
	for(int i=0;i<n;i++){
		l[i]*=-1;r[i]*=-1;
	}
	swap(l,r);
	ans = max(ans,calc());
	cout<<ans<<endl;
	return 0;
}
