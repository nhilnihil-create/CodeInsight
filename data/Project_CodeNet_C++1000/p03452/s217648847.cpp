/// Author : Nhat Huy
/*

 ∧＿＿∧
(。・ω・)つー☆・ * 。
⊂     ノ         .  ゜
 し————Ｊ      Accepted
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "PeopleOnLine"
#define opfin(task) freopen(task".inp", "r", stdin)
#define opfout(task) freopen(task".out", "w", stdout)
#define ms(a) memset(a, 0, sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
typedef vector <ii> vii;
typedef pair <int, double> id;
const int N = 1e5 + 5;
vii adj[N];
int sum[N];
bool ok = true, mark[N];
void dfs(int u) {
	mark[u] = 1;
	REP(i, adj[u].size()) {
		ii v = adj[u][i];
		if (!mark[v.first]) {
			sum[v.first] = sum[u] + v.second;
			dfs(v.first);
		}
		else if (sum[v.first] != sum[u] + v.second) {
			ok = 0;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t begin = clock();
    //opfin(task);
    //opfout(task);
    //Code here !
    ms(mark); ms(sum);
    int n, m;
    cin >> n >> m;
    while (m--) {
    	int u, v, d;
    	cin >> u >> v >> d;
    	adj[u].pb(ii(v, d));
    	adj[v].pb(ii(u,-d));
    }
    FOR(i,1,n) {
    	if (!mark[i]) dfs(i);
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    clock_t end = clock();
    //cerr <<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}


