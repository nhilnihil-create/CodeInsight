#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

const int MAX = 1e5 + 5;
vector <int> adj[MAX];
int deg[MAX], dist[MAX];

int main()
{
	boost;
	int n, m, i, a, b;
	cin >> n >> m;
	fo(i, 0, m) {
		cin >> a >> b;
		++deg[b];
		adj[a].pb(b);
	}
	
	queue <int> q;
	foe(i, 1, n) {
		if(!deg[i]) 
		q.push(i);
	}
	
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		
		for(int v : adj[p]) {
			--deg[v];
			dist[v] = max(dist[v], dist[p] + 1);
			if(!deg[v])
			q.push(v);
		}
	}
	cout << *max_element(dist + 1, dist + n + 1);
}
