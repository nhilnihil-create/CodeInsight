#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> u(n), v(n);
	for(int i = 0; i < n; ++i){
		ll x, y;
		cin >> x >> y;
		u[i] = x + y;
		v[i] = x - y;
	}
	const bool even = (u[0] % 2 == 0);
	for(int i = 0; i < n; ++i){
		if((u[i] % 2 == 0) != even){
			cout << -1 << endl;
			return 0;
		}
		if(even){
			--u[i];
			--v[i];
		}
	}
	const int m = 32;
	cout << (m + (even ? 1 : 0)) << endl;
	for(int i = m - 1; i >= 0; --i){
		cout << (1ll << i) << " ";
	}
	if(even){ cout << 1; }
	cout << endl;
	for(int i = 0; i < n; ++i){
		const ll base = (1ll << m) - 1;
		vector<char> solution;
		ll cu = u[i], cv = v[i];
		for(int j = m - 1; j >= 0; --j){
			const ll d = (2ll << j);
			int dmask = 0;
			if(cu - d >= -base){
				cu -= d;
				dmask |= 1;
			}
			if(cv - d >= -base){
				cv -= d;
				dmask |= 2;
			}
			solution.push_back("LUDR"[dmask]);
		}
		if(even){ solution.push_back('R'); }
		solution.push_back('\0');
		cout << solution.data() << endl;
	}
	return 0;
}

