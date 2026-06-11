#include <iostream>
#include <set>
using namespace std;
set < pair <int, int> > s;
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++ i){
		int x, y;
		cin >> x >> y;
		s.insert(make_pair(x, y));
	}
	int cnt = 0, ans = n;
	for (set < pair <int, int> > :: iterator it = s.begin(); it != s.end(); ++ it){
		int x = (*it).first, y = (*it).second;
		if (x - y == cnt)
			++ cnt;
		if (x - y > cnt)
			ans = min(ans, x - 1);
	}
	cout << ans << endl;
}
