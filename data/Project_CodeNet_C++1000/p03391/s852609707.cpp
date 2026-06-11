#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans,minb=2e9;
bool ok;
int main(){
	scanf("%d",&n);
	while(n--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ans+=b;
		if(a!=b)ok=1;
		if(b<a)minb=min(minb,b);
	}
	if(ok)printf("%lld",ans-minb);
	else puts("0");
	return 0;
} 