#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int N;
int cnt[13] = { 0 };
int vis[24] = { 0 };

int count() {
	int mi = INF;
	REP(i, 24) {
		REP(j, 24) {
			if (vis[i] && vis[j] && i != j) {
				//cout << "K" << endl;
				int d1 = abs(i - j);
				int d2 = 24 - d1;
				int d = min(d1, d2);
				mi = min(mi, d);
			}
		}
	}
	return mi;
}

signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	
	cin >> N;
	VI D(N);
	REP(i, N) {
		cin >> D[i];
		cnt[D[i]]++;
	}
	if (cnt[0]) {
		cout << 0 << endl;
		return 0;
	}
	vis[0] = 1;
	VI v;
	FOR(i, 1, 12) {
		if (cnt[i] == 1)v.push_back(i);
		else if (cnt[i] == 2) {
			vis[i] = 1;
			vis[24 - i] = 1;
		}
		else if (cnt[i] > 2) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	if (cnt[12] == 1)vis[12] = 1;
	else if (cnt[12] >= 2) {
		cout << 0 << endl;
		return 0;
	}


	int M = v.size();
	if (M == 0) {
		cout << count()<< endl;
		return 0;
	}
	

	int ans = 0;
	REP(k, 1 << M) {
		REP(i, M) {
			if (k&(1 << i))vis[v[i]] = 1, vis[24 - v[i]] = 0;
			else vis[v[i]] = 0, vis[24 - v[i]] = 1;
		}
		ans = max(ans, count());
	}
	cout << ans << endl;
	
	return 0;
}

