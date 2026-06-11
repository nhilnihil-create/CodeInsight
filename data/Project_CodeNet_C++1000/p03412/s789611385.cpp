#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<int> a(N), b(N);
		for(auto& t : a) cin >> t;
		for(auto& t : b) cin >> t;
		int res = 0;
		for(int i=0;i<29;i++){
			vector<int> c = b;
			for(auto& t : c) t %= (1 << (i+1));
			sort(c.begin(), c.end());
			int cnt = 0;
			for(int j=0;j<N;j++){
				int sub = a[j] % (1 << (i+1));
				auto p1 = lower_bound(c.begin(), c.end(), (1<<i) - sub);
				auto p2 = lower_bound(c.begin(), c.end(), 2*(1<<i) - sub);
				auto p3 = lower_bound(c.begin(), c.end(), 3*(1<<i) - sub);
				cnt += distance(p1, p2) + distance(p3, c.end());
				cnt %= 2;
			}
			if(cnt%2) res |= (1 << i);
		}
		cout << res << endl;
	}
}
