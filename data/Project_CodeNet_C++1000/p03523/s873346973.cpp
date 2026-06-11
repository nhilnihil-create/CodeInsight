#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;


int main() {
	string s;
	cin >> s;

	bool can = false;

	rep(i, 1 << 4) {
		string t = "";
		if (i % 2)t += "A";
		t += "KIH";
		if ((i / 2) % 2)t += "A";
		t += "B";
		if ((i / 4) % 2)t += "A";
		t += "R";
		if ((i / 8) % 2)t += "A";

		if (s == t)can = true;
	}
	
	cout << (can? "YES":"NO") << endl;
}