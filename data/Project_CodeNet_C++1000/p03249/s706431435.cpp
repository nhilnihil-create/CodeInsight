# include <stdio.h>
# include <bits/stdc++.h>


#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

using namespace std;

inline bool isvowel (char c) {
	c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u') return 1;
    return 0;
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

ll a[N], n, sum;
map < ll, int > u;
vector < int > g[N];
vector < pair < int, int > > edges; 
int cur = 1;
int l[N];
int c[N];
bool cmp (int x,int y) { return a[x] > a[y];}
void dfs (int v, int pr = 0, int dep = 0) {
    //cout << v << '\n';
    sum += dep;
    for (auto to : g[v]) {
        if (to == pr) continue;
        dfs (to, v, dep + 1);
    }
}

int main () { 
    cin >> n;
    For (i, 1, n) {
        cin >> a[i];
        u[a[i]] = i;
        if (a[i] > a[cur]) cur = i;
        l[i] = 1;
        c[i] = i;
    }
    
    sort(c + 1, c + n + 1, &cmp);
    
    For (x, 1, n - 1) {
        int i = c[x];
        //cout << i << ' ' << l[i] << '\n';
        ll dis = a[i] - (n - l[i]) + l[i];
        if (!u.count(dis)) {
            //cout << n << ' ' << l[i] << '\n'; 
            //cout << i << ' ' << dis << '\n';
            puts("-1");
            exit(0);
        }
        if (i == u[dis]) {
            //cout << u[dis] << ' ' << dis << '\n';
            puts("-1");
            exit(0);
        
        }
        int j = u[dis];
		l[j] += l[i];
		edges.pb(mp(i, j));
		g[j].push_back(i);
	}
	cur = c[n];
    dfs(cur);
    if (sum != a[c[n]]) {
        //cout << sum << ' ' << a[c[n]] << '\n';
        puts("-1");
        exit(0);
    }
    
    for (auto it : edges) {
        cout << it.F << ' ' << it.S << '\n';
    }
    return Accepted;
}

// Coded By OB