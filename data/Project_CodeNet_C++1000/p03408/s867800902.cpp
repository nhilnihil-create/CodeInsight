#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<utility>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(A) A.begin(),A.end()
bool comparator(P a, P b) {
	return a.first / a.second < b.first / b.second;
}

int main() {
	map<string, int> m;
	int n, k;
	cin >> n;

	string s;
	rep(i, n) {
		cin >> s
			;
		m[s] += 1;
	}
	cin >> k;
	rep(i, k) {
		cin >> s;
		m[s] -= 1;
	}
	ll max = 0;
	for (auto&& kv : m) {
		if (kv.second > max)max = kv.second;
	}
	cout << max << endl;
}
