#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))


const double pi = 4*atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int num[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	FOR(i,0,n){
		cin >> num[i];
	}

	map<int,int> cnt1;
	map<int,int> cnt2;

	for(int i = 0; i < n; i+=2){
		cnt1[num[i]]++;
	}

	for(int i = 1; i < n; i+=2){
		cnt2[num[i]]++;
	}

	vector<pair<int,int>> c1;
	vector<pair<int,int>> c2;

	for (auto &p : cnt1){
		c1.push_back({-p.S,p.F});
		sort(c1.begin(),c1.end());
		while(c1.size() > 2) {
			c1.pop_back();
		}
	}

	for (auto &p : cnt2){
		c2.push_back({-p.S,p.F});
		sort(c2.begin(),c2.end());
		while(c2.size() > 2) {
			c2.pop_back();
		}
	}

	c1.pb({0,-1});
	c2.pb({0,-2});

	int best = 1000000;

	for (auto &p : c1){
		for(auto &p2 : c2){
			if (p.S != p2.S){
				best=min(best,n+p.F+p2.F);
			}
		}
	}

	cout << best << "\n";

}
