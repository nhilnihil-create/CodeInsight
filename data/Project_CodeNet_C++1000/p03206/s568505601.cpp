#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <utility>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;

int main() {
    int d; cin >> d;
    string s = "Christmas";
    string a = " Eve";
    string ans;
    if(d == 25) ans = s;
    else if(d == 24) ans = s + a;
    else if(d == 23) ans = s + a + a;
    else if(d == 22) ans = s + a + a + a;
    cout << ans << endl; 
	return 0;
} 