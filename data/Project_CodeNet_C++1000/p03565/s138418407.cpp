#include <iostream>
#include <fstream>
#include <cstdio>
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
	if(a < b) return 0;
	return fact[a] * (inv_fact[a-b] * inv_fact[b] % mod) % mod;
}


const int N = 2e5+5;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s, t; cin>>s>>t;
	int n = s.size(), m = t.size();
	
	if(n < m){
		cout<<"UNRESTORABLE\n";
		return 0;
	}
	int target = -1;
	string ans;
	for(int i = n-m; i >= 0; i--){
		bool check = true;
		for(int j = i; j < i+m; j++){
			if(s[j] == '?' || (s[j] == t[j - i])){
			}else check = false;
		}
		if(check){
			string tmp;
			for(int j = 0; j < i; j++){
				tmp += (s[j] == '?' ? 'a' : s[j]);
			}
			tmp += t;
			for(int j = i+m; j < n; j++){
				tmp += (s[j] == '?' ? 'a' : s[j]);
			}
			ans.empty() ? ans = tmp : ans = min(ans, tmp);
		}
	}
	if(ans.empty()){
		cout<<"UNRESTORABLE\n";
		return 0;
	}
	cout<<ans<<"\n";
}