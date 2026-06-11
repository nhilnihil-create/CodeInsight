#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
 
using namespace std;
 
const int maxn=1e7+10;
 
int32_t main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	int n,m;
	scanf("%d %d",&n,&m);
	priority_queue<int> pq;
	for(int i=0;i<n;++i){
		int x;scanf("%d",&x);
		pq.push(-x);
	}
	vii q(m);
	for(int i=0;i<m;++i){
		scanf("%d %d",&q[i].ss,&q[i].ff);
	}
	sort(q.rbegin(),q.rend());
	for(int i=0;i<m;++i){
		int x=q[i].ss,y=q[i].ff;
		if(y>(-pq.top())){
			while(y>(-pq.top()) && x){
				pq.pop();
				pq.push(-y);
				--x;
			}
		}
		else
			break;
	}
	ll ans=0;
	while(!pq.empty()){
		ans+=(-pq.top());
		pq.pop();
	}
	printf("%lld\n",ans);
	return 0;
}