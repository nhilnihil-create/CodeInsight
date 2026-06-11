#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
 
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const ll INF = 1e16;
const ll MOD = 1e9 + 7;
 
#define REP(i, n) for(ll i = 0; i < n; i++)
 
 
 
int main() {
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> a(n);
	REP(i, n){
		cin >> a[i];
	}
 
	ll ans = INF;
	REP(i, n){
		vector<ll> tmp;
		multiset<ll> ms;
		REP(j, n + 1){
			if(j == n || a[j] < a[i]){
				sort(tmp.begin(), tmp.end());
				REP(l, (ll)tmp.size() - k + 1){
					ms.insert(tmp[l]);
				}
				tmp.clear();
			}
			else{
				tmp.push_back(a[j]);
			}
		}
		if(ms.size() < q) continue;
		auto itr = ms.begin();
		REP(j, q - 1) itr++;
		ans = min(ans, *itr - a[i]);
	}
	cout << ans << endl;
}