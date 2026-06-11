#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 200000;
const int MAX2 = 28;

int binarySearch(int *b, int check, int max) {
	int min = -1;
	for (int mid = max >> 1;max - min > 1;mid = min + (max - min >> 1)) {
		if (b[mid] >= check) max = mid;
		else min = mid;
	}
	return max;
}
int main() {
	static int N, a[MAX], b[MAX];
	cin >> N;
	for (int i = 0;i < N;++ i) cin >> a[i];
	for (int i = 0;i < N;++ i) cin >> b[i];
	
	int ans = 0, tmp;
	for (int i = 1 << MAX2;i > 0;i >>= 1) {
		for (int j = 0;j < N;++ j) {
			a[j] &= (i << 1) - 1;
			b[j] &= (i << 1) - 1;
		}
		sort(b, b+N);
		tmp = 0;
		for (int j = 0;j < N;++ j) {
			tmp += binarySearch(b, (i << 2) - a[j], N) - binarySearch(b, (i | i << 1) - a[j], N) + binarySearch(b, (i << 1) - a[j], N) - binarySearch(b, i - a[j], N);
		}
		ans |= (tmp & 1) == 0 ? 0 : i;
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

解説AC、これは無理でした
*/