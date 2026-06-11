#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//freopen("aa.in","r",stdin);
	int i,j,_;
	for(scanf("%d",&_);_--;){
		ll a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		ll s=a*b;
		ll c=(ll)sqrt(s);
		ll ans;
		if(c*c==s){
			ans=(c-1)*2;
			if(a<c)--ans;
		}else{
			ans=c*2;
			if(c*(c+1)>=s)--ans;
			if(a<=c)--ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}