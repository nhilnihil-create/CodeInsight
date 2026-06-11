#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

const int MAX = 3e4;

int n, m, x, y;

vector <int> ans;

main() {
  cin >> n;
  if(n == 3) {
	puts("2 5 63");
	return 0;
  }
  else {
	ans.clear();
	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(4);
	ans.push_back(9);
	for(int i = 15; i <= MAX; i += 12) {
	  if(i + 6 <= MAX) {
		if(ans.size() < n - 1) ans.push_back(i), ans.push_back(i + 6);
	  }
	}
	for(int i = 8; i <= MAX; i += 6)  {
	  if(i + 2 <= MAX) {
		if(ans.size() < n - 1) ans.push_back(i), ans.push_back(i + 2);
	  }
	}
	for(int i = 6; i <= MAX; i += 6) {
	  if(ans.size() < n) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	for(auto V : ans) printf("%d ", V);
  }
}
