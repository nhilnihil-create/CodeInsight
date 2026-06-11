#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
vector<vector<int> > v;
int L = 0, id = 0;
void dfs(int now, int count = 0, int p = -1){
	if(v[now].size() == 1){
		if(L < count) id = now, L = count;
	}
	for(auto& to: v[now]){
		if(to == p) continue;
		dfs(to, count + 1, now);
	}
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    v.resize(n);
    for(int i=1;i<n;i++){
    	cin >> a >> b; 
    	a--,b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    dfs(0); dfs(id);
    cout << ((L % 3 == 1)? "Second": "First") << endl;
    return 0;
}
