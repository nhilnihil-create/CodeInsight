#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli n,k;
	cin>>n>>k;

	vector<pair<lli,lli>> v;
	//各種別で最大のものを探す
	REP(i,0,n){
		lli t,d;
		cin>>t>>d;
		t--;
		v.push_back(make_pair(d,t));
	}
	sort(v.begin(),v.end(),greater<pair<lli,lli>>());

	priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> q;
	set<lli> kind;
	vector<lli> kindCnt(n,0);
	lli sum = 0;
	REP(i,0,k){
		q.push(v[i]);
		sum += v[i].first;
		kind.insert(v[i].second);
		kindCnt[v[i].second]++;
	}
	lli ans = sum+(kind.size())*(kind.size());
	lli now = k;
	while(q.size() && now<n){
		lli topKind = q.top().second;
		lli topValue = q.top().first;
		if(DEBUG)cout<<"topKind="<<topKind<<" topValue="<<topValue<<endl;
		q.pop();
		if(kindCnt[topKind]==1)continue;

		sum -= topValue;
		sum += v[now].first;
		kind.insert(v[now].second);
		q.push(v[now]);
		kindCnt[v[now].second]++;
		ans = max((unsigned lli)ans,sum+(lli)(kind.size())*(kind.size()));
		now++;
	}
	cout<<ans<<endl;
	return 0;
}