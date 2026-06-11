#include <bits/stdc++.h>

using namespace std;
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _b; ++i)
#define fd(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(x) ((int)(x).size())
#define db(x) cout << #x << " == " << x << endl
#define _ << ", " << 
#define X first
#define Y second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define endl '\n'
#define pc putchar
#define gc getchar 
#define bit(i) (1<<(i))

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int maxn=(int)2e5+5,INF=1e9;
int n;
string s;

void enter(){
	cin>>s;
	n=SZ(s);
	s=' '+s+' ';
}

int lst[(1<<26)+123];

int adj[maxn][28],d[maxn];

void process(){
	int sum=0;

	ff(i,0,n+1) d[i]=INF;

	lst[0]=n+1;

	fd(i,n,1){	
		sum^=bit(s[i]-'a');
		adj[i][0]=lst[sum];
		ff(j,1,26) {
			adj[i][j]=lst[sum^bit(j-1)]; 
		}
		// ff(j,0,26) if (adj[i][j]) db(i _ j _ adj[i][j]);
		lst[sum]=i;
	}
	
	d[1]=0;

	ff(i,1,n) if (d[i]!=INF){
		ff(j,0,26) if (adj[i][j]){
			d[adj[i][j]]=min(d[adj[i][j]],d[i]+((adj[i][j]-i)%2==1));
		}
	}
	// ff(i,1,n+1) cout<<d[i]<<' ';cout<<endl;
	if (d[n+1]==0) d[n+1]=1;
	cout<<d[n+1]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	// freopen("test.inp","r",stdin);
	// freopen("test.out","w",stdout);

	enter();
	process();	

	return 0;
}