#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+100;
ll n,Q,k;
char s[N];
ll x[N];

int main(){
	scanf("%lld\n%s\n%lld\n",&n,s,&Q);
	for(ll i=1;i<=Q;i++) scanf("%lld\n",x+i);
	for(ll b=1;b<=Q;b++){
		ll l=x[b]-1;
		queue<ll>q;
		ll cnt=0,ans=0,res=0;
		for(ll i=0;i<n;i++){
			if(s[i]=='D') q.push(cnt);
			if(s[i]=='M') res+=(ll)q.size(),cnt++;
			if(s[i]=='C') ans+=res;
			if(i>=l){
				k=i-l;
				if(s[k]=='D'){
					res-=(cnt-q.front());
					q.pop();
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}