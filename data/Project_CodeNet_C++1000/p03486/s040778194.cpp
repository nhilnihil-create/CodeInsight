#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	int result = s.compare(t);
	if(result < 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}