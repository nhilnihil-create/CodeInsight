#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,int> PP;
ll labs(ll v){
	if(v<0LL)return -v;
	return v;
}

int n;
PP p[100001];
PP p2[100001];
bool used[100001];

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&p[i].first.first,&p[i].first.second);
		p[i].second=i;
		p2[i]=p[i];
	}
	sort(p,p+n);
	reverse(p,p+n);
	for(int i=0;i<n;i++){
		swap(p2[i].first.first,p2[i].first.second);
	}
	sort(p2,p2+n);
	for(int i=0;i<n;i++){
		swap(p2[i].first.first,p2[i].first.second);
	}
	ll now=0;
	ll sum=0;
	int l[2]={0,0};
	int ty=0;
	for(int i=0;i<n;i++){
		P use;
		if(ty==0){
			while(l[0]<n && used[p[l[0]].second])l[0]++;
			if(l[0]==n)break;
			used[p[l[0]].second]=true;
			use=p[l[0]].first;
			l[0]++;
		}else{
			while(l[1]<n && used[p2[l[1]].second])l[1]++;
			if(l[1]==n)break;
			used[p2[l[1]].second]=true;
			use=p2[l[1]].first;
			l[1]++;
		}
		if(use.first>now){
			sum+=(use.first-now);
			now=use.first;
		}
		if(use.second<now){
			sum+=now-use.second;
			now=use.second;
		}
		ty=1-ty;
	}
	sum+=labs(now);
	ll ans=sum;
	now=0;
	sum=0;
	memset(used,false,sizeof(used));
	l[0]=l[1]=0;
	ty=1;
	for(int i=0;i<n;i++){
		P use;
		if(ty==0){
			while(l[0]<n && used[p[l[0]].second])l[0]++;
			if(l[0]==n)break;
			used[p[l[0]].second]=true;
			use=p[l[0]].first;
			l[0]++;
		}else{
			while(l[1]<n && used[p2[l[1]].second])l[1]++;
			if(l[1]==n)break;
			used[p2[l[1]].second]=true;
			use=p2[l[1]].first;
			l[1]++;
		}
		if(use.first>now){
			sum+=(use.first-now);
			now=use.first;
		}
		if(use.second<now){
			sum+=now-use.second;
			now=use.second;
		}
		ty=1-ty;
	}
	sum+=labs(now);
	ans=max(ans,sum);
	printf("%lld\n",ans);
	return 0;
}