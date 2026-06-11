#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

using P = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<P> cnt(n);
	rep(i,n){
		cnt[i].second = i;
	}
	vector<int> a(n), b(n);
	rep(i, n-1)
	{
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
		cnt[a[i]].first++;
		cnt[b[i]].first++;
	}
	sort(rall(cnt));
	vector<ll> c(n);
	rep(i,n){
		cin >> c[i];
	}
	sort(rall(c));
	ll sum = 0;
	REP(i, 1, n)
	{
		sum += c[i];
	}
	queue<int> q;
	q.emplace(cnt[0].second);
	vector<ll> v(n,-1);
	int pos = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		v[x] = c[pos++];
		for (auto y : g[x])
		{
			if(v[y]==-1){
				q.emplace(y);
			}
		}
	}
	cout << sum << "\n";
	rep(i,n){
		if(i){
			cout << " ";
		}
		cout << v[i];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}