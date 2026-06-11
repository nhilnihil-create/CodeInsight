#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

ll N;
ll ans = 0;
ll inf = string::npos;

void dfs(string n){
    if(stoll(n) > N) return;
    if(n.find('3') != inf && n.find('5') != inf && n.find('7') != inf) ans += 1;
    dfs(n + '3');
    dfs(n + '5');
    dfs(n + '7');
}

void solve(){

	cin >> N;
	dfs("3");
	dfs("5");
	dfs("7");
	print(ans);
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}
