#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n, a[1000006];
map <int, int> s;
bool check(int x){
	s.clear();
	for (int i = 1; i <= n; ++ i){
		if (a[i - 1] >= a[i]){
			map <int, int> :: iterator it = s.upper_bound(a[i]);
			map <int, int> :: iterator _it;
			while (it != s.end()){
				_it = it ++;
				s.erase(_it);
			}
			int j = a[i];
			while (s[j] == x - 1 && j)
				s[j --] = 0;
			if (j == 0)
				return false;
			if (s.count(j))
				s[j] ++;
			else
				s[j] = 1;
		}
	}
	return true;
}
int solve(int l, int r){
	int ans = r;
	while (l <= r){
		int m = l + r >> 1;
		if (check(m)){
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	n = read();
	bool flag = true;
	for (int i = 1; i <= n; ++ i){
		a[i] = read();
		if (a[i - 1] >= a[i])
			flag = false;
	}
	if (flag){
		cout << 1 << endl;
		return 0;
	}
	cout << solve(2, 1000000000) << endl;
	return 0;
}
