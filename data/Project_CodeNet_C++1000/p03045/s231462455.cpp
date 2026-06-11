#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
template<typename T>
inline T mod(T n, T mod){ T res = n%mod; if(res < 0) res += mod; return res; }

/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+5;
int p[N], rnk[N];
bitset<N> sei;

int find(int v){
	if(p[v] == v) return v;
	return p[v] = find(p[v]);
}

void merge(int v, int u){
	int x = find(v);
	int y = find(u);
	if(x != y){
		if(rnk[x] > rnk[y]) swap(x, y);
		p[x] = y;
		if(rnk[x] == rnk[y]) rnk[y]++;
	}
}

int main(){
	fastio;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		p[i] = i;
		rnk[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;	
		merge(x, y);
		sei[find(x)] = 1;
	}
	set<int> st, other;
	for(int i = 1; i <= n; i++){
		int k = find(i);
		if(!sei[k]){
			st.insert(k);
		}else other.insert(k);
	}
	cout << endl << len(st)+len(other) << endl;
	return 0;
}