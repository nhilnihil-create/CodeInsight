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

const int maxN = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

bool flag[2];
int x[maxN], y[maxN];
vector <int> vec;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		flag[(x[i] + y[i]) % 2] = true;
	}
	if (flag[0] && flag[1]) return cout << -1 << endl, 0;
	if (flag[0]) vec.push_back(1);
	for (int i = 0; i <= 30; i++){
		vec.push_back(1 << (30 - i));
	}
	cout << (int)vec.size() << endl;
	for (auto v : vec) cout << v << " ";
	cout << endl;
	string s;
	for (int i = 0; i < n; i++){
		s = "";
		for (auto v : vec){
			if (abs(x[i]) > abs(y[i])){
				s += (x[i] > 0 ? 'R' : 'L');
				x[i] += v * (x[i] > 0 ? -1 : +1);
			}
			else{
				s += (y[i] > 0 ? 'U' : 'D');
				y[i] += v * (y[i] > 0 ? -1 : +1);
			}
		}
		cout << s << "\n";
	}
	return 0;
}
 

