// A C++ program that implements Z algorithm for pattern searching 
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef long long ijt;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int sex[100010];
int main(void) {
	int n;cin >> n;
	printf("%d\n",0);fflush(stdout);
	bool M;
	string s;cin >> s;
	if (s == "Vacant") {
		return 0;
	}
	else {
		if(s == "Male") sex[0] = 1;
		else sex[0] = 2;
	}

	printf("%d\n", n-1); fflush(stdout);
	cin >> s;
	if (s == "Vacant") {
		return 0;
	}
	sex[n-1] = 3 - sex[0];

	int l = 0,r = n-1;
	for (int i = 0; i < 18; i++) {
		int mid = (l+r)/2;
		printf("%d\n", mid); fflush(stdout);
		cin >> s;
		if (s == "Vacant") {
			return 0;
		}
		else {
			if(s == "Male") sex[mid] = 1;
			else sex[mid] = 2;
		}
		if (((mid - l) % 2 == 0) == ( sex[mid] == sex[l])) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
}