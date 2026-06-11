#include <bits/stdc++.h>

using namespace std;

#define sz(v)           ((int)((v).size()))
#define clr(v, d)       memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0; i<sz(v); ++i)
#define lp(i, n)        for(int i=0; i<(int)(n); ++i)
#define lpi(i, j, n)    for(int i=(j); i<(int)(n); ++i)
#define lpd(i, j, n)    for(int i=(j); i>=(int)(n); --i)
#define INF             1000000000

//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int N = 1e5+5;
priority_queue<pair<int, int>> all;
priority_queue<pair<int, int>> rep;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > sol;

int vis[N];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, uniq = 0;
	cin >> n >> k;
	lp(i, n){
		pair<int, int> in;
		cin >> in.second >> in.first;
		all.push(in);
	}
	lp(i, n){
		pair<int, int> in = all.top();
		all.pop();
		if(vis[in.second] > 0 || uniq == k)
			rep.push(in);
		else{
			sol.push(in);
			++vis[in.second];
			++uniq;
		}
	}
	lpi(i, uniq, k){
		sol.push(rep.top());
		++vis[rep.top().second];
		rep.pop();
	}
	while(!rep.empty()){
		ll op1 = 0ll + (uniq-1)*(uniq-1) + rep.top().first;
		ll op2 = 0ll + (uniq)*(uniq) + sol.top().first;
		if(op1 > op2){
			sol.pop();
			sol.push(rep.top());
			rep.pop();
			--uniq;
		}
		else
			break;
	}
	ll ans = 0;
	ans = 1ll * uniq * uniq;
	while(!sol.empty()){
		ans += 0ll + sol.top().first;
		sol.pop();
	}
	cout << ans;
	return 0;
}
