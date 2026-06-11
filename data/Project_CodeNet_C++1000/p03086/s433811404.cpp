#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

V<char> b = { 'A','C','G','T' };

int main() {
	
	string s;
	cin >> s;
	int cnt = 0, ans = 0;
	rep(i, s.size()){
		bool acgt = false;
		rep(j, 4)if (s[i] == b[j])acgt=true;
		if (acgt)cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans << endl;

}