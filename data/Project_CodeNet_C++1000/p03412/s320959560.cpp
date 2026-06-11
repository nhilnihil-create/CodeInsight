#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	for(int i = 0; i < n; ++i){ cin >> b[i]; }
	int answer = 0;
	for(int s = 0; s < 30; ++s){
		const int lsb = (1 << s);
		vector<int> aa(n), bb(n);
		for(int i = 0; i < n; ++i){
			aa[i] = a[i] & ((2 << s) - 1);
			bb[i] = b[i] & ((2 << s) - 1);
		}
		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		for(const int x : aa){
			const int t = x & (lsb - 1);
			const auto p0 = lower_bound(bb.begin(), bb.end(), lsb - t);
			const auto p1 = lower_bound(bb.begin(), bb.end(), lsb - t + lsb);
			if(x & lsb){
				if(distance(bb.begin(), p0) & 1){ answer ^= lsb; }
				if(distance(p1, bb.end()) & 1){ answer ^= lsb; }
			}else{
				if(distance(p0, p1) & 1){ answer ^= lsb; }
			}
		}
	}
	cout << answer << endl;
	return 0;
}

