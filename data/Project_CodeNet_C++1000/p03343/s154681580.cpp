#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define INF 1LL << 30
#define ll long long
#define ull unsigned long long
#define RNG mt19937
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;


int main(){
	fast_io();
	int n,k,q;
	cin >> n >> k >> q;
	int a[n];
	bool b[n] = {};
	vector<pii> v;
	cu(i,0,n){cin >> a[i];v.pb({a[i], i});}
	sort(all(v));
	int ans = INF;
	cu(s,0,n){
		priority_queue<int, vector<int>, greater<int>> pq, tm;
		int p = -1;
		fu(i,0,n){
			if(i == n || b[i] == 1){
				int num = i - p - 1 - k + 1;
				while(num-- > 0){
					pq.push(tm.top());
					tm.pop();
				}
				while(tm.size())tm.pop();
				p = i;
			}
			else{
				tm.push(a[i]);
			}
		}
		if(pq.size() >= q){
			int st = pq.top();
			int nd = 0;
			cu(i,0,q){nd = pq.top();pq.pop();}
			gmin(ans,nd - st); 
		}
		b[v[s].S] = 1;
	}
	cout << ans << '\n';
}
