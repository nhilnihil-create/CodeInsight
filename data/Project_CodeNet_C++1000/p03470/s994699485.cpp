#include<iostream>

using namespace std;


int main() {
	int N;
	const int ARRAY_SIZE = 101;
	//配列をglobal変数とすると、int flag[101]だけですべてが0に初期化される。
	//配列の各要素を0で初期化したい時は、{}を使うとよい。
	//要素数が10で{3, 2, 5}で初期化すると、残りの要素を0で初期化してくれる。
	int flag[ARRAY_SIZE] = {};

	cin >> N;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		flag[d] = 1;
	}

	int ans = 0;
	for (int i = 0; i < 101; i++) {
		ans += flag[i];
	}
	cout << ans << endl;


	return 0;
}