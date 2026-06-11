#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
using tii = tuple<int, int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
//#define INF (ll)1E9
#define INF INT_MAX
#define EPS 1E-9
#define MOD 1000000007
#define PI 3.1415926535897932384

template <class T>ostream &operator<<(std::ostream &o, const vector<T> &v)
{
	rep(i, v.size()) {
		o << (i > 0 ? " " : "") << v[i];
	}
	return o;
}

//int dx[]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1,1};
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

//constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
	int a, b;
	cin >> a >> b;
	if (a + b == 15)cout << '+' << endl;
	else if (a*b == 15)cout << '*' << endl;
	else cout << 'x' << endl;
}