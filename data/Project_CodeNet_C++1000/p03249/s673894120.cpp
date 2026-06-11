#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<long long,int> id;
int size[100005];
long long w[100005];
vector<pair<int,int> >e;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long D;
		scanf("%lld",&D);
		id[D]=i;
	}
	for(int i=1;i<=n;i++)size[i]=1,w[i]=0;
	for(int j=1;j<n;j++){
		long long d=id.rbegin()->first;
		int x=id.rbegin()->second;
		id.erase(d);
		d-=n-2*size[x];
		if(!id.count(d)||size[x]*2>n){puts("-1"); return 0;}
		e.push_back(make_pair(id[d],x));
		size[id[d]]+=size[x];
		w[id[d]]+=w[x]+size[x];
	}
	if(size[id.begin()->second]!=n||w[id.begin()->second]!=id.begin()->first){puts("-1"); return 0;}
	for(int i=0;i<e.size();i++)printf("%d %d\n",e[i].first,e[i].second);
	return 0;
}