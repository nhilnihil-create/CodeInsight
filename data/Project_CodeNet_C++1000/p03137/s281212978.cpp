#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	rep(i,m) cin >> v[i];
	sort(v.begin(), v.end());
	priority_queue<int> q;
	ll sum = 0;
	rep(i,m-1) {
		q.push(v[i+1] - v[i]);
		sum += v[i+1] - v[i];
	}
	ll sub = 0;
	rep(i,n-1) {
		if (q.empty()) break;
		sub += q.top();
		q.pop();
	}
	cout << sum - sub << endl;
}