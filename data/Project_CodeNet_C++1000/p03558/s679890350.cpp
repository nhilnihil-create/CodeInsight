#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	deque<pair<int, int>>deq;
	deq.push_front(make_pair(1, 1));
	while (!deq.empty()) {
		auto mon = deq.front();
		deq.pop_front();
		if (v[mon.first] > 0) continue;
		v[mon.first] = 1;
		if (mon.first == 0) {
			cout << mon.second << endl;
			return 0;
		}
		deq.push_front(make_pair((mon.first * 10) % n, mon.second));
		deq.push_back(make_pair((mon.first + 1) % n, mon.second + 1));
	}
}