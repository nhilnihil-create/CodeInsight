#include<iostream>
#include<map>
using namespace std;

int main(void) {
	int N, M;
	string s[100], t[100];
	map<string, int> m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		m[s[i]]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		cin >> t[i];
		m[t[i]]--;
	}
	int ans = 0;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		ans = max(ans, itr->second);
	}
	printf("%d\n", ans);


	return 0;
}
