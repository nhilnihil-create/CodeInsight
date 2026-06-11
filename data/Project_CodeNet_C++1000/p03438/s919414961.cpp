#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	
	ll sum_a = 0, sum_b = 0;
	rep(i, n){
		sum_a += a[i];
		sum_b += b[i];
	}
	
	ll count_a = 0;
	ll count_b = 0;
	rep(i, n){
		if(a[i] < b[i]){
			count_a += (b[i] - a[i] + 1) / 2;
		} else{
			count_b += a[i] - b[i];
		}
	}
	
	if(count_a <= sum_b - sum_a && count_b <= sum_b - sum_a){
		cout << "Yes" << endl;
	} else{
		cout << "No" << endl;
	}
	return 0;
}

