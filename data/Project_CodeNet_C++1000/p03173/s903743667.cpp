using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <set> 
#include <unordered_set>
#include <string>
#include <functional>
#include <limits.h>
//#include <bits/stdc++.h> 
//#include <list>
#include <stack>
#include <stdio.h>
typedef signed long long ll; //watch out ll= int*int will not become ll, rather (ll)ini*int casting will work
#include <queue>
#include <math.h>
#include <deque>
#define ffor(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
//typedef long float lf;
#include <cmath>
#include <iomanip>
#include <numeric>
#include <stdio.h>
const long double PI = 3.141592653589793238L;
/*struct CustomCompare
{
	bool operator()(pii& p1, pii& p2)
	{
		if (p1.second - p1.first == p2.second - p2.first)
			return p1.first > p2.first;

		return p1.second - p1.first < p2.second - p2.first;
	}
};*/
int tt, n, k, inp, a, b, x,m;
void pv(vector<int> a) {
	for (auto i : a)
		cout << i<< ' ';
	cout << '\n';
}
void pv(vector<char> a) {
	for (auto i : a)
		cout << i;
	cout << '\n';
}
void pp (vector<pair<int, int>> a) {
	for (auto i : a)
		cout << i.first << ' ' << i.second<<'\n';
}
void copy(vector<long long>& a, vector<long long>& b) {
	b[0] = a[0];
	for (unsigned i = 1; i < a.size(); i++) {
		b[i] = b[i - 1] + a[i];
	}

}
int tryy(vector<int>& a, int start, int end, int fireball, int berzerk, int k) {
	int counter = start + 1, extra = 0, ans = 0;
	while (counter < end) {
		cout << "yeah";
		if (a[counter] < max(a[start], a[end])) {
			counter++; extra++;
		}
		else {
			if (end - counter >= k) {
				counter += k;
				ans += fireball;
			}
			else {
				extra -= berzerk * (k - (end - counter));
				counter = end;
			}
		}
	}
	cout << "counter extra ans " << counter << ' ' << extra << ' ' << ans << endl;
	//int waste = extra % k;
	//return ans+ extra*min(berzerk*k,fireball)+berzerk;
	return ans + extra / k * min(k * berzerk, fireball) + (extra % k) * berzerk;

}
int main() {
	int n;
	cin >> n; 
	vector<ll>a(n), pref(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	vector<vector<ll>> dp(n);
	for (int i = 0; i < n; i++)
		dp[i] = vector<ll>(n);
	for (int i = 0; i < n; i++)
		dp[i][i] = 0;//a[i];
	for (int k = 1; k <= n-1; k++) {
		for (int i = 0; i + k < n; i++) {
			dp[i][i + k] = LLONG_MAX;
			for (int part = 0; part < k; part++) {
				dp[i][i + k] = min(dp[i][i + k], dp[i][i + part] + dp[i + part + 1][i + k] + pref[i + k] - pref[i] +a[i]);
			}
		}
	}
	cout << dp[0][n - 1];
}