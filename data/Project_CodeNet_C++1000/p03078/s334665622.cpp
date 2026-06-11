#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<cfloat>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(int i=0;i<n;i++)
#define Rip(i,n) for(int i=1;i<=n;i++)
#define RIP(i,a,b) for(int i=a;i<b;i++)
#define all(V) V.begin(),V.end()
#define MOD 1000000007
#define mod 998244353
#define inf MOD 
#define sec setprecision
#define Pair pair<ll,ll>
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using namespace std;
using ll = long long;
using ld = long double;
ll gcd(ll a, ll b)
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll pow(ll x, ll n) {
	x %= mod;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return (pow((x * x) % mod, n / 2) % mod);
	else
		return (x * pow(x, n - 1)) % mod;
}
int main() {
	ll x, y, z, k; cin >> x >> y >> z >> k;
	vector<ll>a(x); rip(i, x)cin >> a[i];
	vector<ll>b(y); rip(i, y)cin >> b[i];
	vector<ll>c(z); rip(i, z)cin >> c[i];
	sort(all(a));
	sort(all(b));
	vector<ll>ans;
	if (x * y * z < 100000) {
		rip(i, x) {
			rip(j, y) {
				rip(s, z) {
					ans.push_back(a[i] + b[j] + c[s]);
				}
			}
		}
		sort(all(ans));
		reverse(all(ans));
		rip(i, k) {
			cout << ans[i] << endl;
		}
	}
	else {
		rip(i, x) {
			rip(j, y)ans.push_back(a[i] + b[j]);
		}
		sort(all(ans));
		reverse(all(ans));
		vector<ll>e(k);
		rip(i, k) {
			e[i] = ans[i];
		}
		vector<ll> kotae;
		rip(i, k) {
			rip(j, z) {
				kotae.push_back(e[i] + c[j]);
			}
		}
		sort(all(kotae));
		reverse(all(kotae));
		rip(i, k)cout << kotae[i] << endl;
	}
}