#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<tuple>
#include<string>
typedef unsigned long long ll;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repm(i,a,b) for(ll i=(a);i>(b);i--)
#define F first
#define S second
using namespace std;
const ll INF = 1e12;
const double PI = 3.1415926535897932;
const int i_INF = 2147483647;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
	int n, a, b;
	cin >> n >> a >> b;
	cout << min({ a,b }) << " " << max({ 0,a + b - n }) << endl;
	return 0;
}