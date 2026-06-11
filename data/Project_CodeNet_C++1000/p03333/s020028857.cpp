#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define fi first 
#define se second

#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VD vector<double>
#define VVD vector<vector<double>>
#define VVVD vector<vector<vector<double>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VVVL vector<vector<vector<ll>>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define VVVB vector<vector<vector<bool>>>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVVS vector<vector<vector<string>>>

#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<ll,ll>
#define VPII vector<pair<int,int>>
#define VVPII vector<vector<pair<int,int>>>
#define VVVPII vector<vector<vector<pair<int,int>>>>
#define VPLL vector<pair<ll,ll>>
#define VVPLL vector<vector<pair<ll,ll>>>
#define VVVPLL vector<vector<vector<pair<ll,ll>>>>

const ll HMOD = (ll)1e9 + 7;
const ll LMOD = 998244353;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;
const long double EPS = 1e-10;


void YN(bool flag) {
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Yn(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void yn(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int main() {
	int N; cin >> N;
	
	vector<pair<pair<ll, ll>, int>> seg1(N),seg2(N);


	REP(i, N) {
		ll L, R;
		cin >> L >> R;
		seg1[i] = { {L,R},i };
		seg2[i] = { {R,L},i };
	}

	sort(ALL(seg1));
	sort(ALL(seg2));

	VB flg(N);
	ll K,pos,ans = -1;

	for (int to12 : {1, 2}) {
		K = 0; pos = 0;
		REP(i, N) flg[i] = true;
		for (int i = 0, j = 0; i < N && j < N;) {

			if (to12 == 1 && i < N) {
				if (flg[seg1[N - 1 - i].second]) {

					if (pos < seg1[N - 1 - i].first.first) {
						K += abs(seg1[N - 1 - i].first.first - pos);
						pos = seg1[N - 1 - i].first.first;
					}
					else if(seg1[N - 1 - i].first.second < pos){
						K += abs(seg1[N - 1 - i].first.second - pos);
						pos = seg1[N - 1 - i].first.second;
					}
					to12 = 2;
					flg[seg1[N - 1 - i].second] = false;
				}
				++i;
			}
			if (to12 == 2 && j < N) {
				if (flg[seg2[j].second]) {

					if (pos < seg2[j].first.second) {
						K += abs(seg2[j].first.second - pos);
						pos = seg2[j].first.second;
					}
					else if (seg2[j].first.first < pos){
						K += abs(seg2[j].first.first - pos);
						pos = seg2[j].first.first;
					}

					to12 = 1;
					flg[seg2[j].second] = false;
				}
				++j;
			}
			
		}
		K += abs(pos);
		ans = max(ans, K);
	}
	
	cout << ans << endl;
	return 0;
}

