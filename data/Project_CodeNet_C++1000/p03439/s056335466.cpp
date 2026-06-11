#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;


int main() {

	int n;
	cin >> n;

	string sex0;
	cout << 0 << endl;
	cin >> sex0;
	if (sex0 == "Vacant")return 0;

	int l = 0, r = n, c;

	while (true) {
		c = (l + r) / 2;

		string res;
		cout << c << endl;
		cin >> res;
		if (res == "Vacant")break;

		if ((res == sex0) ^ (c % 2 == 0))r = c;
		else l = c;
	}
}