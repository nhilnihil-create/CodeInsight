#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 500010;
const int MOD = (ll)1e9 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;

typedef pair<int, int>P;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };


typedef pair<string, string>P2;
int N;
string res = "";
vector<string>bits;
void dfs(int n,string res) {
	if (n == N) {
		bits.pb(res);
		return;
	}
	dfs(n + 1, res + '1');
	dfs(n + 1, res + '0');
}
map<P2,int>mp,mp2;
signed main() {
	string s;
	cin >> N >> s;
	string S = s.substr(0, N);
	string T = s.substr(N, N);
	//print(S); print(T);
	dfs(0,res);
	for (auto str: bits) {
		//print(str);
		string red="", blue="";
		REP(i, N) {
			if (str[i] == '0')red += S[i];
			else blue += S[i];
		}
		VREVERSE(blue);
		//pe(red); print(blue);
		mp[make_pair(red, blue)]++;
	}
	for (auto str : bits) {
		string red="", blue="";
		REP(i, N) {
			if (str[i] == '0')red += T[i];
			else blue += T[i];
		}
		VREVERSE(blue);
		mp2[make_pair(blue, red)]++;
	}
	int ans = 0;
	for (auto x : mp) {
		//pe(x.first.first); print(x.first.second);
		ans += x.second*mp2[x.first];
	}
	print(ans);
}	
