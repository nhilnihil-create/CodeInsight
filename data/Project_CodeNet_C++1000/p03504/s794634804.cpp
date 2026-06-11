#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

typedef struct {
	int s, t, c;
}pro_t;

bool cmp(const pro_t& a, const pro_t& b) {
	return a.s < b.s ;
}
int main() {
	int N, C; cin >> N >> C;
	vector<pro_t> pro(N);
	vector<vector<int>> ch(31, vector<int>(TE + 2));

	for (int i = 0; i < N; i++) {
		 cin >> pro[i].s >> pro[i].t >> pro[i].c;	
	}	
	sort(pro.begin(), pro.end(),cmp);	
	for (int i = 0; i < N; i++) {
		int s = pro[i].s, t = pro[i].t, c = pro[i].c;
		if (ch[c][s + 1] == -1)ch[c][s + 1]++;
		else ch[c][s]++;
		if (ch[c][t] == 1)ch[c][t]--;
		else  ch[c][t + 1]--;
	}
	int ans = 1;
	vector<int> im(31);
	for (int i = 1; i <= 2e5; i++) {
		int temp = 0;
		for (int j = 1; j <= 30; j++) {
			im[j] += ch[j][i];
			temp += im[j];
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
}
