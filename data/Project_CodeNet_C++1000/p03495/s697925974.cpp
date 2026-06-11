#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	
	int num[200000] = { 0 };
	int numa;
	int numb = 0;
	int count = 0; int m = 0;
	cin >> N >> K;
	int K1=0;
	for (int i = 0;i < N;i++) {
		cin >> numa;
		num[numa-1]++;
	}
	for (int i = 0;i < N;i++) {
		if (num[i] != 0) K1++;
	}
	sort(num, num + N);
	if (K1 - K >= 1) {
		while (count != K1- K) {
			m++;
			if (num[m] != 0) {
			numb += num[m];
			count++;
		}
		}
		
	}
	cout << numb;
}