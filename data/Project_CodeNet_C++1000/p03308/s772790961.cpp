#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);

	int max_num = 0;
	int min_num = __INT_MAX__;
	rep(i, n){
		max_num = max(max_num, a.at(i));
		min_num = min(min_num, a.at(i));
	}

	cout << max_num-min_num << endl;
}