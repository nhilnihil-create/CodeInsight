# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<random>
#include<deque>
#include<cstdio>
#include<fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2000100;
const int mod = (int)pow(10, 9) + 7;
const ll INF = 10000000100;
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define ppd pair<double,double>
#define ppp pair<ll,pp>
#define fi first
#define se second
#define pb push_back
#define fix(n) fixed<<setprecision(n)
#define itr vector<ll>::iterator
#define print(s) cout<<s<<endl
#define inp(s) cin>>s
string yn(bool b) { return (b ? "Yes" : "No"); }
string YN(bool b) { return (b ? "YES" : "NO"); }
ll n;
int main() {
	cin >> n;
	ll num = 1,ct=2,m=-1;
	vector<ll>v[1000];
	while (num < 100000) {
		if (num == n)m=ct;
		num += ct; ++ct;
	}
	if (m==-1) {
		cout << "No" << endl;
		return 0;
	}
	else {
		ct = 1;
		rep(i, m) {
			for (int j = i + 1; j < m; ++j) {
				v[i].pb(ct); v[j].pb(ct);
				++ct;
			}
		}
		cout <<"Yes"<<endl<<m<<endl;
		rep(i, m) {
			cout <<v[i].size() << " ";
			rep(j, v[i].size())cout << v[i][j] << (j == v[i].size()-1 ? "\n" : " ");
		}
	}
	return 0;
}