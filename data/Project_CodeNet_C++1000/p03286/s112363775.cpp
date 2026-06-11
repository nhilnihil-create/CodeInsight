#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 4000000000; //4*10^9
constexpr auto MOD = 1000000007; //10^9+7


int main() {

	int n;
	cin >> n;
	vi s(100);
	int keta = 0;

	while (n) {
		s[keta] = abs(n) % (-2);
		n =(n-s[keta])/(-2);
		keta++;
	}

	if (keta == 0) cout << "0" << endl;
	else {
		rep(i, keta)cout << s[keta - i - 1];
		cout << endl;
	}
}