#include<cstdio>
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll d[N];
unordered_map<ll,vector<int> > p;
ll cnt[N],sum[N],n,r[N];
vector<pair<int,int> > w;
bool comp(int a,int b){
	return d[a]>d[b];
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&d[i]),r[i]=i,p[d[i]].push_back(i),cnt[i]=1;
	sort(r+1,r+n+1,comp);
	for (int i=1;i<n;i++){
		ll x=r[i],s=d[x]-(n-2*cnt[x]),y;
		if (p[s].empty()||s>=d[x]){
			cout<<-1<<endl;
			return 0;
		}
		y=p[s].back();
		w.push_back(make_pair(x,y));
		cnt[y]+=cnt[x];
		sum[y]+=sum[x]+cnt[x];
	}
	if (sum[r[n]]!=d[r[n]]){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n-1;i++)printf("%d %d\n",w[i].first,w[i].second);
}