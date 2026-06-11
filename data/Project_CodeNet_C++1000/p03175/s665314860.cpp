#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1


#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); \
						 istream_iterator<string> _it(_ss); \
						 err(_it, args); }
#else
#define error(args...)		42
#endif


void err(istream_iterator<string> it) { cerr << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "; ";
	err(++it, args...);
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif
}

int ceil2(int a, int b){
    int c = a / b;
    if (c * b < a) c++;
    return c;
}

int black(int cur, int par);

int n;

const int lmt = 100007;

vector<int> g[lmt];

vector<int> mem_w(lmt, -1);

vector<int> mem_b(lmt, -1);

int white(int cur, int par)
{
	if(mem_w[cur] != -1)
		return mem_w[cur];

	mem_w[cur] = 1;

	for(auto v: g[cur])
	{
		if(v==par)
			continue;

		mem_w[cur] *= ((white(v, cur)+black(v, cur))%mod);
		mem_w[cur] %= mod;
	}

	return mem_w[cur];
}

int black(int cur, int par)
{
	if(mem_b[cur] != -1)return mem_b[cur];

	mem_b[cur] = 1;

	for(auto v: g[cur])
	{
		if(v==par) continue;

		mem_b[cur] *= (white(v, cur)%mod);
		mem_b[cur] %= mod;
	}

	return mem_b[cur];
}


int32_t main()
{
	c_p_c();

	cin>>n;

	for (int i = 0; i < n-1; ++i)
	{
		int s,d; cin>>s>>d; s--,d--;

		g[s].pb(d);
		g[d].pb(s);
	}

	white(0,-1);
	black(0,-1);

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << mem_w[i] << " ";
	// }
	// cout << "\n";

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << mem_b[i] << " ";
	// }

	// cout << "\n";

	cout << (mem_w[0] + mem_b[0]) % mod;
	
	return 0;
}