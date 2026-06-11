#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const int mod = (int)1e9 + 7;
const int mod2 = 998244353;

ll exp(ll taban, ll us, ll md) {
    ll carpan = taban % md;
	if(carpan == 0) return 0;
    ll temp = us;
    ll res = 1;
    while(temp){
        if(temp % 2) res = (res*carpan) % md;
        temp /= 2;
        carpan = (carpan*carpan) % md;
    }
    return res;
}
 
ll ebob(ll a, ll b){
    if(!a)return b;
    return ebob(b%a, a);
}

ll ekok(ll a, ll b){
    return (a*b)/ebob(a, b);
}
ll mul(ll a, ll b, ll md){
	return a*b % md;
}
vector<ll> fact;
vector<ll> inv_fact;
void fact_init(int n){
	fact.resize(n+5);
	inv_fact.resize(n+5);
	fact[0] = inv_fact[0] = 1;
	for(int i = 1; i <= n; i++){
		fact[i] = (fact[i-1] * i) % mod;
		inv_fact[i] = exp(fact[i], mod-2, mod);
	}
}
ll komb(ll a, ll b){
	return fact[a] * (inv_fact[a-b] * inv_fact[b] % mod) % mod;
}
const int N = 500+5;
int h, w;
vector<vector<int>> ans;
vector<vector<int>> vec(N, vector<int>(N));
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>h>>w;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++){
	   cin>>vec[i][j];
	}
	bool c1 = 0;
	for(int i = 1; i <= h; i++){
		for(int j = (i%2 ? 1 : w); (i%2 ? j <= w : j >= 1); (i%2 ? j++ : j--)){
			int x = vec[i][j];
			if((x & 1) && !c1){
				c1 = true;
			}
			else if(x & 1){
				c1 = false;
			}
			if(c1){
				if(i%2){
					if(j == w && i != h){
						ans.pb({i, j, i+1, j});
						//vec[i+1][j]++;
					}else if(j != w){
						ans.pb({i, j, i, j+1});
						//vec[i][j+1]++;
					}
				}else if(i%2 == 0){
					if(j == 1 && i != h){
						ans.pb({i, j, i+1, j});
						//vec[i+1][j]++;
					}
					else if(j != 1){
						ans.pb({i, j, i, j-1});
						//vec[i][j-1]++;
					}
				}
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x: ans) cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<"\n";
}