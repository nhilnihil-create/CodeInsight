#include <iostream>
#include <utility>
#include <algorithm>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include <math.h>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
#include <deque>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define ll long long
#define pb push_back
using namespace std;

const int N = 2e6, PI = 3.14159265359, M = 1e9 + 7;
typedef pair <ll, ll> pii;
map <ll, ll> dp;
ll a[N], ans = 0;
map <pii, ll> ma;

int main() {
	ll n, ans = 0;
	cin >> n;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for(int i = 0; i < n; i++) {
		if(s1[i] == s2[i]) {
			if(s1[i] == s3[i]) 
				ans += 0;
			else
				ans += 1;
		}
		else {
			if(s1[i] == s3[i])
				ans += 1;
			else if(s2[i] == s3[i])
				ans += 1;
			else 
				ans += 2;
		}
	}
	cout << ans;
}