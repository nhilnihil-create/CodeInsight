#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '2') ans++;
	}
	printf("%d\n", ans);
	return 0;
}
