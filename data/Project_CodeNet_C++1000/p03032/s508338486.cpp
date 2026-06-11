#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	deque<int> dq;
	rep(i, n) {
		int v;
		cin >> v;
		dq.push_back(v);
	}
	int ans = 0;
	for(int a = 0; a <= min(n, k); a++) {
		
		// a: 左から何個取り出すか
		
		for(int b = 0; a+b <= min(n, k); b++) {
			vector<int> my; // 取り出したもの
			deque<int> now = dq;
			rep(i, a) {
				my.push_back(now.front());
				now.pop_front();
			}
			rep(i, b) {
				my.push_back(now.back());
				now.pop_back();
			}
			
			// b: 右から何個取り出すか
			int tmp = 0; 
			sort(all(my));
			for(int i = 0; i < min(k-a-b, a+b); i++) {
				if(my[i]<0) my[i] = 0;
			}
			rep(i, my.size()) {
				tmp += my[i];
			}
			ans = max(ans, tmp);
			
			// cout << a << " " << b << " : ";
			// rep(i, my.size()) cout << my[i] << " ";
			// cout << endl;
		}
	}
	cout << ans << endl;
	return 0;
}