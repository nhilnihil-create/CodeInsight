#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
#define int long long
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define sor(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define rep(i,n) for(ll i=0;i<n;i++)
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)
#define pin pair<ll,ll>
int ze = 0;
signed main(){
	int n; cin >> n;
	vel d(n);
	vector<pin> md(n);
	rep(i, n) { cin >> d[i]; md[i] = make_pair(d[i], i); }
	sor(md);
	vel pa(n, -1);
	vel all_chi(n, 1); vel all_dist(n, 0);
	for(int i=n-1;i>0;i--) {
		pin q = md[i];
		int num = q.second;
		if (all_chi[num] * 2 >= n) { cout << -1 << endl; return 0; }
		int next_val = q.first + 2 * all_chi[num] - n;
		auto next_itr = lowerbound(md, make_pair(next_val, ze));
		if ((*next_itr).first != next_val) { cout << -1 << endl; return 0; }
		int next_num = (*next_itr).second;
		pa[num] = next_num;
		all_chi[next_num] += all_chi[num];
		all_dist[next_num] += all_dist[num] + all_chi[num];
	}
	if(md[0].first!=all_dist[md[0].second]) { cout << -1 << endl; return 0; }
	rep(i, n) {
		if (pa[i] != -1) {
			cout << i+1 << " " << pa[i]+1 << endl;
		}
	}
	return 0;
}