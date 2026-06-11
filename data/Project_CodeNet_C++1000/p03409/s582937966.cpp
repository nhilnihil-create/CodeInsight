#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int mod = 1e9 + 7;
int p = 5e5 + 100;

int main() {	
	vector<ll> com(p + 1);
	vector<ll> inv(p + 1);
	vector<ll> mul(p + 1);
	com[0] = 1;
	for (ll i = 1; i <= p; ++i) {
		com[i] = (com[i - 1] * i) % mod;
	} 
    inv[0] = 1;
    inv[1] = 1;
	for (ll i = 2; i <= p; ++i) {
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod; 
	}
	mul[0] = 1;
	for (int i = 1; i <= p; ++i) {
		mul[i] = (mul[i - 1] * inv[i]) % mod;
	}
	
	
	int n;
	cin >> n;
	set<int> s;
	vector<vector<int>> v(n + n,vector<int> (3,0));
	for (int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
		v[i][2] = 1;
	}
	for (int i = n; i < n + n; ++i) {
		cin >> v[i][0] >> v[i][1];	
	}
	sort(v.begin(),v.end());
	int cnt = 0;
	for (int i = 0; i < n + n; ++i) {
		if (v[i][2] == 1) {
			s.insert(v[i][1]);
			//cout << v[i][1] << endl;
		}else {
			int minn = -1;
			for (auto &x: s) {
				if (x < v[i][1]) {
					minn = max(minn,x);
				}
			//	cout << x << " ";
			}
			//cout << endl;
			if (minn != -1) {
				s.erase(minn);
				cnt++;
			}
		}
	}
	cout << cnt;
}


