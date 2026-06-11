#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int gcd(int x, int y) {
	if (y > x) return gcd(y, x);
	if (y == 0) return x;
	return gcd(y, x % y);
}

bool special(vector<int> v) {
	int sum = 0;
	rep(i, v.size()) {
		sum += v[i];
	}
	rep(i, v.size()) {
		if (gcd(v[i], sum - v[i]) == 1) return false;
	}
	int g = gcd(v[0], v[1]);
	rep(i, (int)v.size() - 2) {
		g = gcd(g, v[i + 2]);
	}
	return g == 1;

}


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int N; cin >> N;
	if (N == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	else if (N == 4) {
		cout << "2 5 20 63" << endl;
		return 0;
	}
	else if (N < 1000) {
		vector<int> v = { 2, 3, 4, 9 ,12 };
		rep(i, N - 5) {
			v.push_back(v[v.size() - 1] + 6);
		}
		//cout << special(v) << endl;
		rep(i, N) {
			if (i != 0) cout << " ";
			cout << v[i];
		}
		cout << endl;
		return 0;
	}
	vector<int> v;
	int tmp = 2;
	rep(i, N + (8 - N % 8) % 8) {
		v.push_back(tmp);
		if (i % 4 == 2 || i % 4 == 3) tmp++;
		tmp++;
	}	auto itr = v.begin();
	while (v.size() > N) {
		if (*itr % 3 == 0 && *itr % 2 == 0) {
			v.erase(itr);
		}
		else {
			itr++;
		}
		//cout << *itr << endl;
	}
	//cout << special(v) << endl;
	rep(i, N) {
		if (i != 0) cout << " ";
		cout << v[i];
	}
	cout << endl;


    return 0;
}
