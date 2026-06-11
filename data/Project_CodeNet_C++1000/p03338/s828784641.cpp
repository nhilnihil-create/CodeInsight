#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	string S;
	cin >> S;
	map<char, int> right, left;
	for (int i = 0; i < S.size(); i++) {
		right[S[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < S.size(); i++) {
		left[S[i]]++;
		right[S[i]]--;
		int cnt = 0;
		for (auto itr = left.begin(); itr != left.end(); itr++) {
			if (itr->second > 0 && right[itr->first] > 0) cnt++;
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
