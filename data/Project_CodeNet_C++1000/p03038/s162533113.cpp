#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<pair<int, int>> cards;
	for(int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		cards.push_back(pair<int, int>(a, 1));
	}
	for(int i = 0; i < M; i++) {
		int b, c;
		scanf("%d %d", &b, &c);
		cards.push_back(pair<int, int>(c, b));
	}
	sort(cards.rbegin(), cards.rend());
	
	int cnt = N, index = 0;
	long max_value = 0;
	while(cnt > 0) {
		pair<int, int> p = cards[index];
		if(cnt >= p.second) {
			max_value += (long)p.first * p.second;
		} else {
			max_value += (long)p.first * cnt;
		}
		cnt -= p.second;
		index++;
	}
	printf("%ld", max_value);
	
	return 0;
}