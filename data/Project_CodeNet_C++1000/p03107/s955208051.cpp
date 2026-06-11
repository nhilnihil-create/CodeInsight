#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int ans = 0;
	stack<int> tower;
	for (int i = 0; i < S.size(); i++) {
		if (tower.empty() || S[i] == tower.top()) {
			tower.push(S[i]);
		} else {
			tower.pop();
			ans += 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}
