#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* A = new int[N];
	int score = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	
	while (1) {
	for (int i = 0; i < N; i++) {
			if (A[i] % 2 == 0)
				score++;  //2の倍数である要素の数
		}
	if (score == N) { //すべて2の倍数なら
		score = 0; //スコアの初期化
		++count;    //試行できる回数のカウント
			for (int i = 0; i < N; i++)
				A[i] /= 2;
	}
	else break;
}
	cout << count;
}