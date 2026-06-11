#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

map<ll, int> prime_factor(ll n){
	map<ll, int> res;
	for(ll i = 2; i*i<=n; i++){
		while(n%i==0){
			res[i]++;
			n/=i;
		}
	}
	if(n!=1) res[n]++;
	return res;
}


int main(){
    int n;
    cin >> n;
    map<ll, int> mp;
    for(int i = 1; i <= n; i++) {
        auto p = prime_factor(i);
        for(auto u : p) {
            mp[u.first] += u.second;
        }
    }
    int a2, a4, a14, a24, a74;
    a2 = a4 = a14 = a24 = a74 = 0;
    for(auto p : mp) {
        if(p.second >= 74) a74++;
        if(p.second >= 24) a24++;
        if(p.second >= 14) a14++;
        if(p.second >= 4) a4++;
        if(p.second >= 2) a2++;
    }
    ll ans = 0;
    ans += a74;
    ans += a24*(a2-1);
    ans += a14*(a4-1);
    ans += (a4*(a4-1)/2)*(a2-2);
    cout << ans << endl;
}