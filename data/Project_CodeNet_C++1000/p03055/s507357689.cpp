#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif



ll n;
vector<int> v[200001];

int t = 0;
int max_distance = 0;
void dfs( int node, int parent, int dist ){
	if ( max_distance < dist ){
		max_distance = dist;
		t = node;
	}
	for ( auto next_node : v[node] ){
		if ( next_node != parent )
			dfs( next_node, node, dist+1 );
	}
}

int main(){
	cin >> n;
	rep(i,n-1){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs( 0, -1, 0 );
	dfs( t, -1, 0 );
	
	//cout << max_distance << endl;
	
	cout << (max_distance%3 == 1 ? "Second" : "First" ) << endl;
	
	return 0;
}


