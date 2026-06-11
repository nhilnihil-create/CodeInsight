#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sq = sqrt(1 + 8 * n + 0.01);


	if (sq*sq == 1 + 8 * n && (1+sq)%2==0) {
		int k = (1 + sq) / 2;
		cout << "Yes" << endl;
		vector<vector<int>> ans(k);
		
		int m = 1;
		rep(i,k) {
			for (int j = i+1; j < k;j++) {
				ans[i].push_back(m);
				ans[j].push_back(m);

				m++;
			}
		}


		cout << k << endl;
		rep(i, k) {
			cout << k - 1;
			for (int a: ans[i]) {
				cout << ' ' << a;
			}
			cout << endl;
		}

	}
	else {
		cout << "No" << endl;
	}



	return 0;
}