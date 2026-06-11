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
#define int long long int
std::string to_stringx(int val)
{
	char buffer[std::numeric_limits<int>::digits10 + 1
		+ 2]; // '-' + '\0'
	std::sprintf(buffer, "%d", val);
	return buffer;
}

int digitsum(int n) {
	int ret = 0;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

double rate(int n) {
	return n / (double)digitsum(n);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int K; cin >> K;

	vector<int> v;
	rep(i, 15) {
		REP(j, 1, 150) {
			string T = to_stringx(j);
			int tmp = i;
			while (tmp--) T.push_back('9');
			int num = stoll(T);
			auto itr = find(v.begin(), v.end(), num);
			if (itr == v.end()) {
				v.push_back(stoll(T));
			}
		}
	}
	sort(v.begin(), v.end());
	//rep(i, v.size()) cout << v[i] << endl;
	rep(i, v.size()) {
		bool flag = false;
		//cout << v[i] << " " << rate(v[i]) << endl;
		REP(j, i + 1, v.size() - 1) {
			//cout << v[j] << " " << rate(v[j]) << endl;
			if (rate(v[i]) > rate(v[j])) {
				flag = true;
				break;
			}
		}
		if (flag) {
			v.erase(v.begin() + i);
			i--;
		}
	}
	rep(i, K) {
		cout << v[i] << endl;
	}


    return 0;
}
