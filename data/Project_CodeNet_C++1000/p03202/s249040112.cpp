//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int n, pos[200200], num[200200], sz;
vi a;
bool check(int x) {
	sz = 0;
	for(int i = 1; i < a.size(); i++) {
		if(a[i]>a[i-1]) continue;
		int j = a[i];
		while(j) {
			if(pos[sz-1]>j) {--sz; continue;}
			if(!sz||pos[sz-1]<j) {
				pos[sz]=j;
				num[sz]=0;
				sz++;
			}
			if(++num[sz-1]>=x) {
				sz--;
				j--;
			} else
				break;
		}
		if(!j) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	ll ans = 0;
	for(int i = 1<<17; i; i>>=1)
		if(!check(ans+i)) ans += i;
	cout << 1+ans;
}
