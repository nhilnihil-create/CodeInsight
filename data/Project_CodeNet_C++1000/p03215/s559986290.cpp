#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1005];
ll sum[1005];
ll bea[1000005];
vector<ll> wei[50];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
void add(ll b,ll num){
	ll pos=0;
	while(b!=0){
		if(b&1)
			wei[pos].push_back(num);
		b>>=1;
		pos++;
	}
}
void copy(vector<ll>t,set<ll>&ans){
	ans.clear();
	for(ll i=0;i<t.size();i++)
		ans.insert(t[i]);
}
set<ll>ans,tmp;
vector<ll>s,as;
int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	ll num=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			bea[num]=sum[j]-sum[i];
			//cout<<bea[num]<<endl;
			add(bea[num],num);
			num++;
		}
	}	
	/*for(int i=0;i<10;i++){
		for(int j=0;j<wei[i].size();i++)
			cout<<wei[i][j]<<" ";
		cout<<endl;
	}*/
	
	ll out=0;
	ll i=45;
	for(;i>=0;i--){
		if(wei[i].size()>=k){
			if(out==0){
				copy(wei[i],ans);
				out+=qpow(2,i);
			} 
			else{
				s.clear();
				set_intersection(ans.begin(),ans.end(),wei[i].begin(),wei[i].end(),back_inserter(s));
				if(s.size()<k)
					continue;
				copy(s,ans);
				out+=qpow(2,i);
			}
		}
	}
	printf("%lld",out);
}