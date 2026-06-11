//#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <tuple>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }


#define INF 100000000
using namespace std;
using ll = long long;



vector < pair<string, int>> p(100);
int order[100];

void allSwap(int a) {
	swap(p[a].first, p[a + 1].first);
	swap(p[a].second, p[a + 1].second);
	swap(order[a], order[a + 1]);
}

int main() {
	int n;
	cin >> n;
	rep(i, n) {
		string s; int a;
		cin >> s >> a;
		p[i].first = s;
		p[i].second = a;
		order[i] = i + 1;
	}
	int j = n - 1;
	while (j > 0) {
		rep(i, j) {
			if (p[i].first > p[i + 1].first) {
				allSwap(i);
			}
			else if (p[i].first == p[i + 1].first && p[i].second < p[i + 1].second) {
				allSwap(i);
			}
		}
		j--;
	}
	rep(i, n) {
		cout << order[i] << endl;
	}
}