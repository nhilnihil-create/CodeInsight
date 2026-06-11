#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define ci cin
#define co cout
#define en endl
#define ln cout<< '\n'
#define rep(i, n) for(int i = 0; i < n; i++)
#define outl(x) cout<< (x) << '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

llint gcd(llint a, llint b)
{
    return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
	return a / gcd(a, b) * b;
}

llint cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
	llint n, p;
	ci >> n >> p;

	if(n == 1) {
		co << p << en;
		return 0;
	}
	
	llint ans = 0;
	for(llint i = 1; i <= sqrt(p) + 1; i++) {
	    llint ai = pow(i, (n - 1));
	    llint tmp = p / ai;
	    if(p % ai) continue;
	    ans = max(ans, gcd(i, tmp));
	}
	
	co << ans << en;
  
	return 0;
}
