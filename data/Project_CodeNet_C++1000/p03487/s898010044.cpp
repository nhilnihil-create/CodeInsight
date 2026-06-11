#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

signed main(void) {
	int n;
	cin >> n;
	map<int, int>a;
	rep(i, n) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	int ret = 0;
	for (auto itr = a.begin(); itr != a.end(); ++itr) {
		int key = itr->first;       // キーを表示
		int value = itr->second;
		//cout << "key= " << key << " value= " << value << endl;
		if (value < key) ret += value;
		else if (value > key) ret += (value - key);
	}
	print(ret);
}