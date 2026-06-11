#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 200000000000000;
constexpr auto MOD = 1000000007;

int main() {

	string s;
	cin >> s;

	rep(i, 3) {
		if (s[i] == '1')s[i] = '9'; 
		else if (s[i] == '9')s[i] = '1';
	}

	cout << s << endl;
}