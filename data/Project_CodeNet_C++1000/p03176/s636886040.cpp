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

const int MXN = 2*100005+5;
int t[4*MXN];

// 0-based indexing; see striver video
// tl, tr: current node v segment; l,r :query segment
int query(int v, int tl, int tr, int l, int r)
{
	// current node seg completely lies inside query seg
	if(tl>=l && tr<=r)
		return t[v];

	// current node seg didn't overlap
	if(tl>r || tr<l)
		return -inf;

	// partially overlap
	int mid = (tl + tr)/2;
	int left = query(2*v+1, tl, mid, l, r);
	int right = query(2*v+2, mid+1, tr, l, r);

	return max(left, right);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
	if(tl==tr)
	{
		t[v] = new_val;
		return;
	}

	int mid = (tl + tr)/2;

	if(pos <= mid)
		update(2*v+1, tl, mid, pos, new_val);
	else
		update(2*v+2, mid+1, tr, pos, new_val);

	t[v] = max(t[2*v+1], t[2*v+2]);
}

void init_t()
{
	for (int i = 0; i < 4*MXN; ++i)
	{
		t[i] = 0;
	}
}


int32_t main()
{
	c_p_c();

	init_t();

	int n; cin>>n;

	int h[n]; 

	for (int i = 0; i < n; ++i)
	{
		cin>>h[i];
	}

	int v[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	int dp[n];

	int ans = -inf;

	for (int i = 0; i < n; ++i)
	{
		int mx = query(0, 0, MXN-1, 0, h[i]-1);
		dp[i] = mx + v[i];
		error(mx, v[i]);
		update(0, 0, MXN-1, h[i], dp[i]);

		ans = max(ans, dp[i]);
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << dp[i] << " ";
	// }

	cout << ans;

	return 0;
}