#include <iostream>
#include <bits/stdc++.h>
#define t97 1000000007

using namespace std;
typedef long long ll;

void dm(vector<vector<ll> >& m) {
    for(ll i = 0; i < m.size(); i++) {
        for(ll j = 0; j < m[i].size(); j++) {
            if(j != m[i].size()-1) {
                cout << m[i][j] << " ";
            } 
            else {
                cout << m[i][j] << endl;
            }
        }
    }
}

void dv(vector<ll>& v) {
    for(ll i = 0; i < v.size()-1; i++) {
        cout << v[i]<<" ";
    }
    cout << v[v.size()-1]<<endl;
}

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

ll minval(ll a, ll b) {
    if(a < b) {
        return a;
    }
    return b;
}

ll maxval(ll a, ll b) {
    if(a > b) {
        return a;
    }
    return b;
}

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

ll powmod(ll a, ll b, ll mod){
    if(b == 0)return 1;
    if(b%2 == 0){
        ll c = powmod(a,b/2, mod);
        return (c*c)%mod;
    }
	else{
        return (a*powmod(a,b-1, mod))%mod;
    }
}

ll modInverse(ll A,ll M)
{
    return powmod(A,M-2,M);
}

void solve() {
	
}

bool winner(ll k, vector<ll>& v, vector<ll>& dp, ll level) {
//	cout << "Level "<< level << endl;
	if(k == 0) {
		return false;
	}
	if(dp[k] == 1) {
		return true;
	}
	if(dp[k] == 0) {
		return false;
	}
	bool wins = false;
	for(ll i = 0;i < v.size(); i++) {
		if(v[i] <= k) {
			wins = (wins || (!winner(k-v[i], v, dp, level+1)));
		}
		if(wins) {
			dp[k] = 1;
			return true;
		}
	}
	dp[k] = 0;
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout);
	ll n, k;
	cin>>n>>k;
	vector<ll> v(n);
	for(ll i = 0; i < n; i++) {
		cin>>v[i];
	}
	vector<ll> dp(k+1, -1);
	if(winner(k, v, dp, 0)) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
    
    return 0;
}