

#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair

#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define dump(x)  cerr << #x << " = " << (x) << endl
#define ALL(t) (t).begin(),(t).end()

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }


const int nax = 1e5+7;
int dp[nax];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	dp[0] = 0;

	for (int i = 0; i <= k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if((i-v[j] >= 0) && dp[i - v[j]] == 0){
				dp[i] = 1;
			}
		}
	}
	if(dp[k] == 0)std::cout << "Second" << "\n";
	else std::cout << "First" << "\n";

	return 0;
}
