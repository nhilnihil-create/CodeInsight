#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

bool flag;
string s;
vector <int> vec;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> s; n = (int)s.size();
	flag = (s[0] == '1' && s[n - 1] == '0');
	for (int i = 0; i < n - 1; i++){
		flag &= (s[i] == s[n - 2 - i]);
		if (s[i] == '1') vec.push_back(i);
	}
	if (!flag) return cout << -1 << endl, 0;
	int len = (int)vec.size() + 2;
	for (int i = 0; i < vec.size(); i++){
		cout << i + 1 << " " << i + 2 << "\n";
	}
	for (int i = 1; i < vec.size(); i++){
		for (int j = 0; j < vec[i] - vec[i - 1] - 1; j++){
			cout << i + 1 << " " << len + j << "\n";
		}
		len += vec[i] - vec[i - 1] - 1;
	}
	return 0;
}
 

