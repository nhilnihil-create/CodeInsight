#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	ll ans = 0;
	ll tmp = n/k;
	ans += tmp * tmp * tmp;
	if(k % 2 == 0){
		vector<ll> res(k, 0);
		for(int i = 1; i <= n; i++){
			res.at(i % k)++;
		}
		for(int i = 1; i < k; i++){ //一つの数のあまりがiの時
			if(k - 2 * i == 0){
				ans += res.at(i) * res.at(k-i) * res.at(k-i);
			}
		}
	}
	cout << ans << endl;
} 