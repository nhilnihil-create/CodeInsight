#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
vector<ll> sum_ab;
vector<ll> a;
vector<ll> b;
vector<ll> c;
ll x,y,z,k;
bool check(ll mid){
	ll cnt = 0;
	for(int i = 0;i < z;i++){
		cnt += sum_ab.end() - lower_bound(sum_ab.begin(),sum_ab.end(),mid-c[i]);
	}
	if(cnt >= k)return true;
	else return false;
}
int main(){
	cin >> x >> y >> z >> k;
	a.resize(x);
	b.resize(y);
	c.resize(z);
	for(ll i = 0;i < x;i++)cin >> a[i];
	for(ll i = 0;i < y;i++)cin >> b[i];
	for(ll i = 0;i < z;i++)cin >> c[i];

	for(ll i = 0;i < x;i++){
		for(ll j = 0;j < y;j++){
			sum_ab.push_back(a[i]+b[j]);
		}
	}

	sort(sum_ab.begin(),sum_ab.end());

	ll ok = 0, ng = 1e18;
	while(ng - ok > 1){
		ll mid = (ok + ng) / 2;
		if(check(mid)){
			ok = mid;
		}
		else ng = mid;
	}

	vector<ll> ans;
	for(ll i = 0;i < z;i++){
		for(ll j = x * y - 1;j >= 0;j--){
			if(c[i] + sum_ab[j] <= ok)break;
			else ans.push_back(c[i]+sum_ab[j]);
		}
	}

	sort(ans.begin(),ans.end(),greater<ll>());
	ll sz = (ll)ans.size();
	for(ll i = 0;i < sz;i++){
		cout << ans[i] << endl;
	}
	for(ll i = 0;i < k - sz;i++)cout << ok << endl;

}
