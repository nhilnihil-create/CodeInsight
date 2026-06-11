 #include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
using T=tuple<int,bool,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m; cin >> n >> m;
	vector<T>x;
	int a,b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		x.eb(a,0,i); x.eb(b-1,1,i);
	}
	sort(all(x));
	set<int>s;
	vector<bool>vis(m);
	int ans = 0;
	for(int i=0; i<(int)x.size(); i++){
		int cor_x, ind;
		bool c;
		tie(cor_x,c,ind)=x[i];
		if(c){
			if(!vis[ind]){
				for(auto id:s)vis[id]=1;
				ans++;
			}
			s.erase(ind);
		}else{
			s.insert(ind);
		}
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
