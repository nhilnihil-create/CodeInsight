#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define pb push_back
#define sz size
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int visited[200010], cnt_a[200010], cnt_b[200010], n, m; 
char s[200010] ; 
vi adj[200010] ;
map<int,bool> mm[200010] ;

void assign_val(int x , int y){
	if(s[x] == 'A') cnt_a[y]++; 
	else cnt_b[y]++;
	if(s[y] == 'A') cnt_a[x]++; 
	else cnt_b[x]++;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m) ; 
	scanf("%s" , s+1) ;
	for(int i = 0 ; i <= m ; i++){
		int a , b ; 
		scanf("%d%d", &a, &b) ; 
		if(mm[a][b]) continue ;
		adj[a].pb(b) ; adj[b].pb(a) ;
		assign_val(a,b) ; 
		mm[a][b] = 1 ;
	}
	int cnt = 0 ;
	queue<int> q ;
	// for(int i = 1; i<=n ; i++) cout << cnt_a[i] << " " << cnt_b[i] << endl ; 
	for(int i = 1; i<=n ; i++) if(cnt_a[i] == 0 || cnt_b[i] == 0) q.push(i), cnt++ , visited[i] = 1 ;
	// cout << cnt << endl ; 
	while(!q.empty()){
		int cur = q.front() ; q.pop() ;
		// if(visited[cur]) continue ;
		// cout << "---------" << cur << "------------\n" ;
		// for(int i = 1; i<=n ; i++) cout << i << ": " << cnt_a[i] << " " << cnt_b[i] << endl ; 
		visited[cur] = 1 ;
		for(int v: adj[cur]){
			if(visited[v]) continue; 
			if(s[cur] == 'A') cnt_a[v]--;
			else cnt_b[v]--;
			if(cnt_a[v] == 0 || cnt_b[v] == 0) q.push(v), cnt++ , visited[v] = 1; 
		}
	}
	// cout << cnt << endl ; 
	if(cnt == n) cout << "No" ;
	else cout << "Yes" ; 
	return 0 ;
}