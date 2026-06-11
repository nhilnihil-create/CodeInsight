#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

map<char, int> mp;
string S,cpy;
int ans;

int main() {
	cin.tie(0);
	cout.tie(0);

	ios::sync_with_stdio(false);

	cin >> S;
	int N = S.length();

	int mae = 0;
	int usiro = N - 1;
	bool flag = false;

	while (usiro - mae > 0) {
		if (S[mae] == S[usiro]) {
			mae++; usiro--;
			continue;
		}
		if (S[mae] == 'x') {
			ans++;
			mae++;
			continue;
		}
		if (S[usiro] == 'x') {
			ans++;
			usiro--;
			continue;
		}
		flag = true;
		break;
	}



	if (flag)cout << -1 << endl;
	else cout << ans << endl;


	return 0;
}
