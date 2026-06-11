#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int N;
int main() {
	vector<int> evenNotDivBy3;
	vector<int> evenDivBy3;
	vector<int> oddMultOf3;
	for (int i = 2; i <= 30000; i++) {
		if (i % 2 == 0) {
			if (i % 3 != 0) {
				evenNotDivBy3.push_back(i);
			} else {
				evenDivBy3.push_back(i);
			}
		} else {
			if (i % 3 == 0) {
				oddMultOf3.push_back(i);
			}
		}
	}
	scanf("%d", &N);
	if (N  == 3) {
		printf("%d %d %d", 2, 5, 63);
	} else if (N == 4) { 
		printf("%d %d %d %d", 2, 5, 20, 63);
	}	else if (N <= 15000) {
		for (int i = 0; i < 2; i++) {
			printf("%d %d ", evenNotDivBy3[i], oddMultOf3[i]);
		}
		int cnt = N - 4;
		for (int i = 2; i < evenNotDivBy3.size() && cnt > 1; i += 2) {
			printf("%d %d ", evenNotDivBy3[i], evenNotDivBy3[i + 1]);
			cnt -= 2;
		}
		for (int i = 2; i < oddMultOf3.size() && cnt > 1; i += 2) {
			printf("%d %d ", oddMultOf3[i], oddMultOf3[i + 1]);
			cnt -= 2;
		}
		if (N % 2) {
			printf("%d ", evenDivBy3[0]);		
		}
	} else {
		int cnt = N;
		for (int n : evenNotDivBy3) {
			printf("%d ", n);
			cnt--;
		}
		for (int n : oddMultOf3) {
			printf("%d ", n);
			cnt--;
		}
		for (int i = 0; i < cnt; i++) {
			printf("%d ", evenDivBy3[i]);
		}
	}
	printf("\n");
	return 0;
}
