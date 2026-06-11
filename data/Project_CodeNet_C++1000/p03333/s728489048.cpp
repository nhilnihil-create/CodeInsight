#include <bits/stdc++.h>
using namespace std ;
#define N 100010

int n;
int main(){
	scanf("%d",&n) ;
	vector <int> l(n+1),r(n+1) ;
	for (int i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]) ;
	sort(l.rbegin(),l.rend()) ;//反向迭代器
	sort(r.begin(),r.end()) ;
	long long ans=0 ;
	for (int i=0;i<=n;i++){
		if (l[i]<r[i]) break ;
		ans+=l[i]-r[i] ;
	}
	ans*=2 ;
	printf("%lld\n",ans) ;
}