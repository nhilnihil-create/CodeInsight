#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
bool used[10001];

int main(){	
	int N;
	cin >> N;
	int a, b;
	set<int> st[N];
	for (int i=0; i<N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		st[a].insert(b);
		st[b].insert(a);
	}
	vector<int> c(N);
	for (int i=0; i<N; i++) {
		cin >> c[i];	
	}
	
	queue<int> que;
	// 0からの深さを各頂点につける
	que.push(0);
	used[0] = true;
	vector<int> dep(N);
	while(!que.empty()) {
		int t = que.front();
		que.pop();
		while(!st[t].empty()) {
			int ins = *st[t].begin();
			st[t].erase(ins);
			if (!used[ins]) {
				used[ins] = true;
				que.push(ins);
				dep[ins] = dep[t]+1;
			}
		}
	}

	priority_queue<P> que2;
	rep(i, N) {
		que2.push(P(dep[i], i));
	}

	SORT(c);
	int M = 0;
	vector<int> d(N,-1);
	rep(i, N) {
		int s = que2.top().second;
		que2.pop();
		d[s] = c[i];
		if (i != N-1) M += c[i];
	}

	cout << M << endl;
	rep(i, N) {
		cout << d[i];
		if (i != N-1) cout << " "; else cout << endl;
	}
	return 0;
}
