#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum(ll x){
	ll res=0;
	while(x)res+=x%10,x/=10;
	return res;
}
ll num(vector<int>x){
	ll res=0;
//	for(int i=x.size()-1;i>=0;i--)printf("%d\n",x[i]);
	for(int i=x.size()-1;i>=0;i--)res=res*10+x[i];
	return res;
}
vector<int> get(ll x){
	vector<int>res;
	while(x)res.push_back(x%10),x/=10;
	return res;
}
ll f(ll x){
	vector<int>tmp1=get(x);
	double mn=1e18;ll res=-1;
	for(int i=0;i<tmp1.size();i++)
		for(int d=tmp1[i];d<=9;d++){
		vector<int>tmp2=tmp1;tmp2[i]=d;
		for(int j=0;j<i;j++)tmp2[j]=9;
		ll y=num(tmp2),sy=sum(y);
		if((double)y/sy<mn)mn=(double)y/sy,res=y;
	}
	return res;
}
ll n;
int main(){
//	vector<int>tmp=get(1000);
//	for(int i=0;i<tmp.size();i++)printf("%d\n",tmp[i]);
//	ll tmp2=num(tmp);
//	printf("%lld\n",tmp2);
	scanf("%lld",&n);
	for(ll i=1,ans=1;i<=n;i++,ans=f(ans+1))
		printf("%lld\n",ans);
	return 0;
}