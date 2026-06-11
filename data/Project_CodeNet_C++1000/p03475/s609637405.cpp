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
	vector<int>c(n-1);
	vector<int>s(n-1);
	vector<int>f(n-1);
	vector<pair<int, int>>point(n);
	rep(i, n-1) {
		cin >> c[i] >> s[i] >> f[i];
	}
	rep(i, n) {
		point[i] = make_pair(i, 0);//point,time
	}
	rep(i, n-1) {
		rep(j, n) {
			if (point[j].first == i) {
				int time = point[j].second;
				while (true) {
					if (time >= s[i] && time%f[i] == 0)break;
					time++;
				}
				point[j].first++;
				point[j].second = time+c[i];
			}
		}
	}
	rep(i, n) {
		cout << point[i].second << endl;
	}
}