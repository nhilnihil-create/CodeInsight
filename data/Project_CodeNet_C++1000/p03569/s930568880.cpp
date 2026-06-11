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
	string s; cin>>s;
	int n = s.size();
	string s_without_x;
	for(int i = 0; i < s.size(); i++){
		char x = s[i];
		if(x != 'x') s_without_x += x;
	}
	int m = s_without_x.size();
	for(int i = 0; i < m/2; i++){
		if(s_without_x[i] != s_without_x[m - 1 - i]){
			cout<<-1;
			return 0;
		}
	}
	int orta = 0;
	int ilk_orta = -1;
	int ikinci_orta = -1;
	for(int i = 0; i < s.size(); i++){
		char x = s[i];
		/*if(x != 'x' && m == 1){
			orta++;
			ilk_orta = i;
			ikinci_orta = i;
		}*/
		if(x != 'x' && orta < (m+1)/2){
			orta++;
			ilk_orta = i;
			ikinci_orta = i;
		}else if(orta == (m+1)/2 && m%2 == 0 && x != 'x'){
			orta++;
			ikinci_orta = i;
		}
	}
	if(ilk_orta == -1){
		cout<<0;
		return 0;
	}
	int ans = 0;
	int l = ilk_orta, r = ikinci_orta;
	//cout<<l<<" "<<r<<endl;
	while(l >= 0 || r < n){
		while(l >= 0 && s[l] != s[r] && r < n){
			if(s[l] == 'x'){
				l--;
				ans++;
			}else{
				r++;
				ans++;
			}
		}
		l--;
		r++;
		if(l < 0){
			while(r < n){
				ans++;
				r++;
			}
		}else if(r >= n){
			while(l >= 0){
				ans++;
				l--;
			}
		}
	}
	cout<<ans<<endl;
}