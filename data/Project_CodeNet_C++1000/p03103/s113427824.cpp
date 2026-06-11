#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	
	int N, M;
	int a, b;
	int cnt = 0;
	long long int ans = 0;
	cin >> N >> M;
	vector<pair<int, int>>p(N);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		p.at(i) = make_pair(a, b);
	}
	
	sort(p.begin(), p.end());
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < p.at(i).second; j++) {
			if (cnt < M) {
				cnt++;
				ans += p.at(i).first;
			}
			else break;
		}
	}
		cout << ans << endl;
	return 0;
}
