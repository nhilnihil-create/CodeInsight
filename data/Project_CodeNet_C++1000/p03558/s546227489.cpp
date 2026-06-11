#include <iostream>
#include <deque>

using namespace std;

bool visited[100000];

int main(int argc, char *argv[]) {
	int K;
	cin >> K;

	deque<pair<int, long long>> q;

	q.push_front(make_pair(1, 1));
	while (!q.empty()) {
		auto e = q.front();
		q.pop_front();
		auto n = e.first;
		auto d = e.second;

		if (n == 0) {
			cout << d << endl;
			break;
		}

		if (visited[n]) continue;
		visited[n] = true;

		q.push_front(make_pair((n * 10) % K, d));
		q.push_back(make_pair((n + 1) % K, d + 1));
	}

	return 0;
}