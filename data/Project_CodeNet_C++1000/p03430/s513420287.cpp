#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); i--)
#define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a,value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 333;

int DP[MAX][MAX][MAX];
string s;

int get(int l, int r, int k)
{
//	cout<<l<<' '<<r<<' '<<k<<endl;
	if (l > r) return 0;

	if (DP[l][r][k] != -1) return DP[l][r][k];
	
	int res = 0;
	
	if (s[l] == s[r])
	{
		int add = 1;
		if (l != r) add++;
		res = max(res, get(l+1, r-1, k) + add);
	}
	
	res = max(res, get(l+1, r, k));
	res = max(res, get(l, r-1, k));
	
	if (k)
	{
		int add = 1;
		if (l != r) add++;
		res = max(res, get(l+1, r-1, k-1) + add);
	}
	
	return DP[l][r][k] = res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);
	
	cin>>s;
	int k;
	cin>>k;
	
	FILL(DP, -1);
	
	int res = get(0, SZ(s)-1, k);
	cout<<res<<endl;
}
