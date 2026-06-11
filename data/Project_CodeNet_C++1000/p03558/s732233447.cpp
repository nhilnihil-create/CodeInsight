#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#define PP std::pair<int,int>
int N[100010];
std::vector<PP> D[100010];
int K;
int main() {
	int K;
	std::cin >> K;
	for (int i = 0; i < K; i++) {
		N[i] = 1 << 30;
	}
	for (int i = 1; i < K; i++) {
		D[i].push_back({ (i + 1) % K,1 });
		D[i].push_back({ (i * 10) % K,0 });
	}
	std::deque<PP> q;
	q.push_front({ 1,1 });
	while (1) {
		PP p = q.front();
		q.pop_front();
		//std::cout << p.first << std::endl;
		if (p.first == 0) {
			std::cout << p.second << std::endl;
			return 0;
		}
		for (auto u : D[p.first]) {
			if (N[u.first] > p.second + u.second) {
				N[u.first] = p.second + u.second;
				if (u.second == 0) {
					q.push_front({ u.first,p.second });
				}
				else {
					q.push_back({ u.first,p.second + 1 });
				}
			}
		}
	}
}
