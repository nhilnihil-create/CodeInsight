#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans=0,prep[20];
const long long mod=1e9+7;
map < pair <long long,long long> , int > cnt;
void bt(int l,int r){
	int sz=r-l+1;
	for(int mask=0;mask<(1<<sz);mask++){
		long long prd1=0,prd2=0;
		if(l==0){
			for(int i=0;i<sz;i++){
				if(mask&(1<<i)){
					prd2*=30LL;
					prd2=(prd2+1LL*(s[l+i]-'a'+1))%mod;
				}
				else{
					prd1*=30LL;
					prd1=(prd1+1LL*(s[l+i]-'a'+1))%mod;
				}
			}
			cnt[make_pair(prd1,prd2)]++;
		}
		else{
			for(int i=sz-1;i>=0;i--){
				if(!(mask&(1<<i))){
					prd2*=30LL;
					prd2=(prd2+1LL*(s[l+i]-'a'+1))%mod;
				}
				else{
					prd1*=30LL;
					prd1=(prd1+1LL*(s[l+i]-'a'+1))%mod;
				}
			}
			ans+=cnt[make_pair(prd1,prd2)];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>s;
	prep[0]=1;
	for(int i=1;i<=19;i++){
		prep[i]=(prep[i-1]*30LL)%mod;
	}
	bt(0,n-1);
	bt(n,n*2-1);
	cout<<ans;
}
