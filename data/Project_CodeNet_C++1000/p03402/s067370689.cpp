
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;


int main() {
	vector<vector<string>>m(100,vector<string>(100));
	rep(i, 0, 50) {
		rep(j, 0, 100) {
			m[i][j] = ".";
			m[99 - i][j] = "#";
		}
	}

	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (cnt < b - 1) {
		m[2*(cnt/ 50)][(2*cnt) % 100] = "#";
		cnt++;
	}

	cnt = 0;
	while (cnt < a - 1) {
		m[99 - 2 * (cnt / 50)][(2 * cnt) % 100] = ".";
		cnt++;
	}

	cout << "100 100" << endl;
	rep(i, 0, 100) {
		rep(j, 0, 100) {
			cout << m[i][j];
		}
		cout << endl;
	}



	return 0;
}