#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	deque<int> d(N);
	for(int i = 0; i < N; i++) scanf("%d", &d[i]);
	
	int times = min(N, K);
	long max_value = 0;
	for(int a = 0; a <= times; a++) {
		for(int b = 0; b <= times - a; b++) {
			vector<int> have;
			long value = 0;
			for(int i = 0; i < a; i++) {
				int tmp = d[i];
				have.push_back(tmp);
				value += tmp;
			}
			for(int i = 0; i < b; i++) {
				int tmp = d[N-1-i];
				have.push_back(tmp);
				value += tmp;
			}
			
			sort(have.begin(), have.end());
			for(int i = 0; i < min(K - a - b, (int)have.size()); i++) {
				if(have[i] < 0) value -= have[i];
			}
			if(max_value < value) max_value = value;
		}
	}
	
	printf("%ld", max_value);
	return 0;
}